require 'json'

package = JSON.parse(File.read(File.join(__dir__, '..', 'package.json')))

Pod::Spec.new do |s|
  s.name           = 'ExpoMapboxNavigation'
  s.version        = package['version']
  s.summary        = package['description']
  s.description    = package['description']
  s.license        = package['license']
  s.author         = package['author']
  s.homepage       = package['homepage']
  s.platforms      = { :ios => '13.4', :tvos => '13.4' }
  s.swift_version  = '5.9'
  s.source         = { git: 'https://github.com/YoussefHenna/expo-mapbox-navigation' }
  s.static_framework = true

  s.dependency 'ExpoModulesCore'
  s.dependency 'MapboxMaps', ENV['ExpoNavigationMapboxMapsVersion']
  s.dependency 'Turf', '~> 4.0.0'

  s.source_files = "**/*.{h,m,swift}"
  s.exclude_files = ["Frameworks/*.xcframework/**/*.h"]
  s.preserve_paths = [
    "Frameworks/*.xcframework",
    "**/*.h",
    "Frameworks/*.xcframework/**/*.h"
  ]

  s.vendored_frameworks=[
    'Frameworks/_MapboxNavigationHelpers.xcframework',
    'Frameworks/MapboxDirections.xcframework',
    'Frameworks/MapboxNavigationCore.xcframework',
    'Frameworks/MapboxNavigationNative.xcframework',
    'Frameworks/MapboxNavigationUIKit.xcframework',
    'Frameworks/Turf.xcframework',
  ]

  # Swift/Objective-C compatibility
  s.pod_target_xcconfig = {
    'DEFINES_MODULE' => 'YES',
    'SWIFT_COMPILATION_MODE' => 'wholemodule',
    'OTHER_SWIFT_FLAGS' => '$(inherited)'
  }

end
