Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '13.0'
  spec.name                       = 'LivingMapLiveSDK'
  spec.version                    = '11.1.0'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMapLiveSDK 11.1.0 for iOS 13.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/LivingMap/releases/download/11.1.0/LivingMapLiveSDK.xcframework.zip'}
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_framework         = 'LivingMapLiveSDK.xcframework'
  spec.user_target_xcconfig       = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.pod_target_xcconfig        = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
end
