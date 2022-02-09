Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '10.0'
  spec.name                       = 'LivingMapLiveSDK'
  spec.version                    = '10.3.6'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMapLiveSDK 10.3.6 for iOS 10.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/distribution-iOS/releases/download/LIVEv10.3.6/LivingMapLiveSDK.xcframework.zip'
  }
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_framework         = 'LivingMapLiveSDK.xcframework'
end
