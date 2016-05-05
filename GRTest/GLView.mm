//
//  GLView.m
//  GRTest
//
//  Created by roko on 5/5/16.
//  Copyright © 2016 roko. All rights reserved.
//

#import "GLView.h"

@implementation GLView

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

+ (Class) layerClass
{
    return [CAEAGLLayer class];
}

@end
