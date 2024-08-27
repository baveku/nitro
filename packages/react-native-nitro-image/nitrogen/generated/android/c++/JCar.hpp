///
/// JCar.hpp
/// Tue Aug 27 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#pragma once

#include <fbjni/fbjni.h>
#include "Car.hpp"

#include "JPerson.hpp"
#include "JPowertrain.hpp"
#include "Person.hpp"
#include "Powertrain.hpp"
#include <optional>
#include <string>

namespace margelo::nitro::image {

  using namespace facebook;

  /**
   * The C++ JNI bridge between the C++ struct "Car" and the the Kotlin data class "Car".
   */
  struct JCar final: public jni::JavaClass<JCar> {
  public:
    static auto constexpr kJavaDescriptor = "Lcom/margelo/nitro/image/Car;";

  public:
    /**
     * Convert this Java/Kotlin-based struct to the C++ struct Car by copying all values to C++.
     */
    [[maybe_unused]]
    Car toCpp() {
      static const auto clazz = javaClassStatic();
      static const auto fieldYear = clazz->getField<double>("year");
      double year = this->getFieldValue(fieldYear);
      static const auto fieldMake = clazz->getField<jni::JString>("make");
      jni::local_ref<jni::JString> make = this->getFieldValue(fieldMake);
      static const auto fieldModel = clazz->getField<jni::JString>("model");
      jni::local_ref<jni::JString> model = this->getFieldValue(fieldModel);
      static const auto fieldPower = clazz->getField<double>("power");
      double power = this->getFieldValue(fieldPower);
      static const auto fieldPowertrain = clazz->getField<JPowertrain>("powertrain");
      jni::local_ref<JPowertrain> powertrain = this->getFieldValue(fieldPowertrain);
      static const auto fieldDriver = clazz->getField<JPerson>("driver");
      jni::local_ref<JPerson> driver = this->getFieldValue(fieldDriver);
      return Car(
        year,
        make->toStdString(),
        model->toStdString(),
        power,
        powertrain->toCpp(),
        driver != nullptr ? std::make_optional(driver->toCpp()) : std::nullopt
      );
    }

  public:
    /**
     * Create a Java/Kotlin-based struct by copying all values from the given C++ struct to Java.
     */
    [[maybe_unused]]
    static jni::local_ref<JCar::javaobject> fromCpp(const Car& value) {
      return newInstance(
        value.year,
        jni::make_jstring(value.make),
        jni::make_jstring(value.model),
        value.power,
        JPowertrain::fromCpp(value.powertrain),
        value.driver.has_value() ? JPerson::fromCpp(value.driver.value()) : nullptr
      );
    }
  };

} // namespace margelo::nitro::image
