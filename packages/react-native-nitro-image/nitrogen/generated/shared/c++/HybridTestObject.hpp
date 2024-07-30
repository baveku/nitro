///
/// HybridTestObject.hpp
/// Tue Jul 30 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#if __has_include(<NitroModules/HybridObject.hpp>)
#include <NitroModules/HybridObject.hpp>
#else
#error NitroModules cannot be found! Are you sure you installed NitroModules properly?
#endif



#include "Func_std__future_std__string_.hpp"
#include "Func_void_std__string.hpp"

namespace margelo::nitro::image {

  using namespace margelo::nitro;

  /**
   * An abstract base class for `TestObject`
   * Inherit this class to create instances of `HybridTestObject` in C++.
   * @example
   * ```cpp
   * class TestObject: public HybridTestObject {
   *   // ...
   * };
   * ```
   */
  class HybridTestObject: public HybridObject {
    public:
      // Constructor
      explicit HybridTestObject(): HybridObject(TAG) { }

      // Destructor
      ~HybridTestObject() { }

    public:
      // Properties
      

    public:
      // Methods
      virtual std::optional<std::variant<std::string, double>> getMap() = 0;
      virtual std::future<void> getValueFromJsCallback(const Func_std__future_std__string_& callback, const Func_void_std__string& andThenCall) = 0;

    protected:
      // Tag for logging
      static constexpr auto TAG = "TestObject";

    private:
      // Hybrid Setup
      void loadHybridMethods() override;
  };

} // namespace margelo::nitro::image