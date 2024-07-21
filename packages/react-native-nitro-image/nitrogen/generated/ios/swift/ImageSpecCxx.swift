///
/// ImageSpecCxx.swift
/// Sun Jul 21 2024
/// This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
/// https://github.com/mrousavy/react-native-nitro
/// Copyright © 2024 Marc Rousavy @ Margelo
///

import Foundation
import NitroModules

/**
 * A class implementation that bridges ImageSpec over to C++.
 * In C++, we cannot use Swift protocols - so we need to wrap it in a class to make it strongly defined.
 *
 * Also, some Swift types need to be bridged with special handling:
 * - Enums need to be wrapped in Structs, otherwise they cannot be accessed bi-directionally (Swift bug: https://github.com/swiftlang/swift/issues/75330)
 * - Other HostObjects need to be wrapped/unwrapped from the Swift TCxx wrapper
 * - Throwing methods need to be wrapped with a Result<T, Error> type, as exceptions cannot be propagated to C++
 */
public class ImageSpecCxx {
  private var implementation: ImageSpec

  public init(_ implementation: ImageSpec) {
    self.implementation = implementation
  }

  // Properties
  public var size: ImageSize {
    get {
      return self.implementation.size
    }
  }
  
  public var pixelFormat: Int32 {
    get {
      return self.implementation.pixelFormat.rawValue
    }
  }
  
  public var someSettableProp: Double {
    get {
      return self.implementation.someSettableProp
    }
    set {
      self.implementation.someSettableProp = newValue
    }
  }

  // Methods
  public func toArrayBuffer(format: Int32) -> Result<Void, Error> {
    do {
      let result = try self.implementation.toArrayBuffer(format: ImageFormat(rawValue: format)!)
      return .success(result)
    } catch {
      return .failure(error)
    }
  }
  
  public func saveToFile(path: String) -> Result<Void, Error> {
    do {
      let result = try self.implementation.saveToFile(path: path)
      return .success(result)
    } catch {
      return .failure(error)
    }
  }
}
