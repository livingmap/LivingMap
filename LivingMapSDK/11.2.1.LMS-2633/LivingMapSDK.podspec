Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '13.0'
  spec.name                       = 'LivingMapSDK'
  spec.version                    = '11.2.1.LMS-2633'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMapSDK 11.2.1.LMS-2633 for iOS 13.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/LivingMap/releases/download/11.2.1.LMS-2633/LivingMapSDK.xcframework.zip'}
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_frameworks        = 'LivingMapSDK.xcframework'
  spec.user_target_xcconfig       = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO'}
  spec.pod_target_xcconfig        = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64', 'ONLY_ACTIVE_ARCH' => 'NO'}
end
