#
# Be sure to run `pod lib lint LLWaterCameraKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'LLWaterCameraKit'
  s.version          = '1.0.0'
  s.summary          = 'A short description of LLWaterCameraKit.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/howoften/LLWaterCameraKit'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'howoften' => 'liujianga@998.com' }
  s.source           = { :git => 'https://github.com/howoften/LLWaterCameraKit.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.dependency 'HXPhotoPickerKit'
  s.ios.deployment_target = '10.0'

  s.requires_arc = true  # 是否是 arc 环境
  #s.source_files = 'LLWaterCameraKit/Classes/LLWaterCameraKit.framework/Headers/*.{h}'  # 因为是使用 .framework 所以只暴露头文件
  s.vendored_frameworks = ['LLWaterCameraKit/Classes/LLWaterCameraKit.framework'] #  .framework 资源路径
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  # s.resource = 'LLWaterCameraKit/Classes/LLWaterCameraKit.framework/Headers'
  # s.resource_bundles = {  # 图片资源
  #   'XXXXX' => ['XXXXX/Assets/*.png']
  # }
  s.public_header_files = 'LLWaterCameraKit/Classes/LLWaterCameraKit.framework/Headers/*.{h}'  # framework 暴露的头文件
  s.frameworks = 'Foundation', 'CoreFoundation', 'UIKit'  # 依赖的 frameworks

end
