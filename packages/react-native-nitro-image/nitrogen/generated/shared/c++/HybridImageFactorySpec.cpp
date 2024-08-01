///
/// HybridImageFactorySpec.cpp
/// Thu Aug 01 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

#include "HybridImageFactorySpec.hpp"

namespace margelo::nitro::image {

  void HybridImageFactorySpec::loadHybridMethods() {
    // load base methods/properties
    HybridObject::loadHybridMethods();
    // load custom methods/properties
    registerHybridMethod("loadImageFromFile", &HybridImageFactorySpec::loadImageFromFile, this);
    registerHybridMethod("loadImageFromURL", &HybridImageFactorySpec::loadImageFromURL, this);
    registerHybridMethod("loadImageFromSystemName", &HybridImageFactorySpec::loadImageFromSystemName, this);
    registerHybridMethod("bounceBack", &HybridImageFactorySpec::bounceBack, this);
  }

} // namespace margelo::nitro::image