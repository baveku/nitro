import { indent } from '../../stringUtils.js'
import { getHybridObjectName } from '../getHybridObjectName.js'
import { createFileMetadataString } from '../helpers.js'
import type { HybridObjectSpec } from '../HybridObjectSpec.js'
import type { SourceFile } from '../SourceFile.js'
import { createFbjniHybridObject } from './FbjniHybridObject.js'

// TODO: Make this customizable
const PACKAGE = 'com.margelo.nitro.image'
// TODO: Make this customizable
const CPP_LIB_NAME = 'NitroImage'

export function createKotlinHybridObject(spec: HybridObjectSpec): SourceFile[] {
  const name = getHybridObjectName(spec.name)
  const properties = spec.properties
    .map((p) => p.getCode('kotlin', { doNotStrip: true, virtual: true }))
    .join('\n\n')
  const methods = spec.methods
    .map((p) => p.getCode('kotlin', { doNotStrip: true, virtual: true }))
    .join('\n\n')

  const abstractClassCode = `
${createFileMetadataString(`${name.HybridT}.kt`)}

package ${PACKAGE}

import android.util.Log
import androidx.annotation.Keep
import com.facebook.jni.HybridData
import com.facebook.proguard.annotations.DoNotStrip
import com.margelo.nitro.HybridObject

/**
 * A Kotlin class representing the ${spec.name} HybridObject.
 * Implement this abstract class to create Kotlin-based instances of ${spec.name}.
 */
@DoNotStrip
@Keep
@Suppress("KotlinJniMissingFunction")
abstract class ${name.HybridT}: HybridObject {
  @DoNotStrip
  @Keep
  private val mHybridData: HybridData

  init {
    mHybridData = initHybrid()
  }

  private external fun initHybrid(): HybridData

  // Properties
  ${indent(properties, '  ')}

  // Methods
  ${indent(methods, '  ')}

  companion object {
    private const val TAG = "${name.HybridT}"
    init {
      try {
        Log.i(TAG, "Loading ${CPP_LIB_NAME} C++ library...")
        System.loadLibrary("${CPP_LIB_NAME}")
        Log.i(TAG, "Successfully loaded ${CPP_LIB_NAME} C++ library!")
      } catch (e: Error) {
        Log.e(TAG, "Failed to load ${CPP_LIB_NAME} C++ library! Is it properly installed and linked? " +
                    "Is the name correct? (see \`CMakeLists.txt\`, at \`add_library(...)\`)", e)
        throw e
      }
    }
  }
}
  `.trim()

  const cppFiles = createFbjniHybridObject(spec)

  const files: SourceFile[] = []
  files.push({
    content: abstractClassCode,
    language: 'kotlin',
    name: `${name.HybridT}.kt`,
    platform: 'android',
  })
  files.push(...cppFiles)
  return files
}