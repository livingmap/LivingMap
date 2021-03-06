Pod::Spec.new do |spec|
  spec.ios.deployment_target      = "13.0"
  spec.name                       = "LivingMapSDK"
  spec.version                    = "11.1.1"
  spec.license                    = { 
    :type => "Copyright", 
    :text => "Living Map" 
  }
  spec.homepage                   = "http://www.livingmap.com"
  spec.authors                    = { 
    "Living Map" => "tech@livingmap.com" 
  }
  spec.summary                    = "LivingMapSDK 11.1.1 for iOS 13.0 and above"
  spec.source                     = { :http => "https://github.com/livingmap/LivingMap/releases/download/11.1.1/LivingMapSDK.xcframework.zip"}
  spec.swift_version              = "5.0"
  spec.frameworks                 = "WebKit", "Foundation"
  spec.vendored_frameworks        = "LivingMapSDK.xcframework"
  spec.pod_target_xcconfig        = { "EXCLUDED_ARCHS[sdk=iphonesimulator*]" => "arm64", "ONLY_ACTIVE_ARCH" => "NO"}
end
