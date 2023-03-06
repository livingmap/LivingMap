Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '13.0'
  spec.name                       = 'AviationAccelerator'
  spec.version                    = '11.3.3'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMap AviationAccelerator 11.3.3 for iOS 13.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/LivingMap/releases/download/11.3.3/AviationAccelerator.xcframework.zip'}
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_frameworks        = 'AviationAccelerator.xcframework'
  spec.dependency                   'LivingMapSDK'
  spec.user_target_xcconfig       = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO'}
  spec.pod_target_xcconfig        = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO'}
end
