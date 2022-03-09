Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '13.0'
  spec.name                       = 'AviationAccelerator'
  spec.version                    = '11.0.0'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMap AviationAccelerator 11.0.0 for iOS 13.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/LivingMap/releases/download/11.0.0/AviationAccelerator.xcframework.zip'}
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_frameworks        = 'AviationAccelerator.xcframework'
  spec.dependency                   'LivingMapSDK'
  spec.dependency                   'LivingMapLiveSDK'
  spec.dependency                   'SwiftProtobuf'
end
