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
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@interface GLView : UIView {
    EAGLContext * m_context;
}

- (void) drawView;

@end
