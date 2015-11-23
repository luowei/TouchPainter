//
//  StrokeSizeCommand.h
//  TouchPainter
//
//  Created by Carlo Chung on 11/9/10.
//  Copyright 2010 Carlo Chung. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Command.h"

@class SetStrokeSizeCommand;

@protocol SetStrokeSizeCommandDelegate

- (void) command:(SetStrokeSizeCommand *)command 
                didRequestForStrokeSize:(CGFloat *)size;

@end


@interface SetStrokeSizeCommand : Command 
{
  @private
  id <SetStrokeSizeCommandDelegate> __unsafe_unretained delegate_;
}

@property (nonatomic, unsafe_unretained) id <SetStrokeSizeCommandDelegate> delegate;

- (void) execute;

@end
