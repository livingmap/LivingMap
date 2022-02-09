Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '10.0'
  spec.name                       = 'LivingMapSDK'
  spec.version                    = '10.3.7'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMapSDK 10.3.7 for iOS10.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/LivingMap/releases/download/SDKv10.3.7/LivingMapSDK.xcframework.zip'}
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_frameworks        = 'LivingMapSDK.xcframework'
  spec.dependency                   'SwiftProtobuf'
  spec.dependency                   'Alamofire'
end
