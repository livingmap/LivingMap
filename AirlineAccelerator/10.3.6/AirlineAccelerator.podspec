Pod::Spec.new do |spec|
  spec.ios.deployment_target      = '10.0'
  spec.name                       = 'AirlineAccelerator'
  spec.version                    = '10.3.6'
  spec.license                    = { 
    :type => 'Copyright', 
    :text => 'Living Map' 
  }
  spec.homepage                   = 'http://www.livingmap.com'
  spec.authors                    = { 
    'Living Map' => 'tech@livingmap.com' 
  }
  spec.summary                    = 'LivingMap AirlineAccelerator 10.3.6 for iOS 10.0 and above'
  spec.source                     = { :http => 'https://github.com/livingmap/distribution-iOS/releases/download/AAv10.3.6/AirlineAccelerator.xcframework.zip'
  }
  spec.swift_version              = '5.0'
  spec.frameworks                 = 'WebKit', 'Foundation'
  spec.vendored_frameworks        = 'AirlineAccelerator.xcframework'
  spec.dependency                   'LivingMapSDK'
  spec.dependency                   'LivingMapLiveSDK'
  spec.dependency                   'SwiftProtobuf'
  spec.dependency                   'Alamofire'
end
