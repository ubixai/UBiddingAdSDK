
Pod::Spec.new do |s|
  s.name             = 'UBiddingAdSDK'
  s.version          = '4.0.0'
  s.summary          = 'UBiddingAdSDK'
  s.homepage         = 'https://www.ubixai.com/product/md'
  s.author           = { 'zhugq' => 'guoqiang.zhu@ubixai.com' }
  s.source           = { :git => 'https://github.com/ubixai/UBiddingAdSDK.git', :tag => s.version.to_s }
  s.ios.deployment_target = '12.0'

  s.static_framework = true
  s.vendored_frameworks = 'UBiddingAdSDK.xcframework'

  s.dependency 'UBiXDaq'
end
