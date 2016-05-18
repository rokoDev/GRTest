//
//  GLView.h
//  GRTest
//
//  Created by roko on 5/5/16.
//  Copyright © 2016 roko. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <QuartzCore/QuartzCore.h>
#import "Interfaces.hpp"

@interface GLView : UIView {
    IApplicationEngine* m_applicationEngine;
    IRenderingEngine * m_renderingEngine;
    EAGLContext * m_context;
    float m_timestamp;
    IResourceManager* m_resourceManager;
}

@property (strong, nonatomic) EAGLContext * context;

- (void) drawView: (CADisplayLink*) displayLink;

@end
