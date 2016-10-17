#import <Cocoa/Cocoa.h>
#import <OpenGL/gl3.h>
#import <AppKit/NSOpenGLView.h>
#import <Metal/Metal.h>

#include "testout.h"


void	w_start_graf()
{
	id <MTLDevice> mtlDevice = MTLCreateSystemDefaultDevice();
	id <MTLCommandQueue> mtlCommandQueue = [mtlDevice newCommandQueue];
	MTLRenderPipelineDescriptor *mtlRenderPipelineDescriptor = [MTLRenderPipelineDescriptor new];
	mtlRenderPipelineDescriptor.colorAttachments[0].pixelFormat = MTLPixelFormatBGRA8Unorm;
	void *lolilol = malloc(100);
	id <MTLBuffer> test = [mtlDevice newBufferWithBytes:lolilol length:100 options:MTLResourceCPUCacheModeDefaultCache];
	id <MTLCommandBuffer> mtlCommandBuffer = [mtlCommandQueue commandBuffer];
}
