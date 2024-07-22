#include <functional>
#include <iostream>
#include <locale>
#include <memory>
#include <stdexcept>
#include <type_traits>
#include <utility>
template <typename FnSig> struct Function {
  static_assert(!std::is_same_v<FnSig, FnSig>,
                "Not a valid function signature");
  ;
};

template <typename Ret, typename... Args> struct Function<Ret(Args...)> {
  struct FuncBase {
    virtual Ret call(Args... args) = 0;
    virtual ~FuncBase() = default;
  };
  template <typename F> struct FuncImpl : FuncBase {
    F f;
    FuncImpl(F f) : f(std::move(f)) {}
    virtual Ret call(Args... args) override {
      //      return f(std::forward<Args>(args)...);
      return std::invoke(f, std::forward<Args>(args)...);
    }
  };
  std::shared_ptr<FuncBase> m_base;
  ~Function() = default;

  template <typename F, typename = std::enable_if_t<
                            std::is_invocable_r_v<Ret, F &, Args...>>>
  Function(F f) : m_base(std::make_shared<FuncImpl<F>>(std::move(f))) {}

  Ret operator()(Args... args) const {
    if (!m_base) [[unlikely]]
      throw std::runtime_error("function not initialized");
    return m_base->call(std::forward<Args>(args)...);
  }
};

void print_func(int x) { printf("#%d, %s\n", x, "Hello"); }

int main() {
  typedef void (*pfunc)(int x);
  pfunc f = print_func;
  Function<void(int)> func(f);
  func(10);
}