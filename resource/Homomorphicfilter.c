/*
 * 中文说明
 * 如果你下载或使用本代码说明你已阅读并同意本声明
 * 此代码由谭升（Tony）开发，并允许任何人，或团体下载，使用此代码用于任何商业或非商业用途
 * 使用本代码时必须复制此声明
 * 本函数库版权归谭升所有.
 * 如有第三方，例如部分使用OpenCV函数，OpenCV函数库版权属于Intel公司，将在后续版本中去除这些函数，特此声明
 
 * English
 * If you download or use the code that you have read and agree to this statement,
 * This code by Tan Sheng (Tony) development, and allow any person, or group to download,
 * use for any commercial or non-commercial use
 * Use the code must be copied to this statement
 * Copyright (C) 2015,Tony, all rights reserved.
 * Part of the use of the OpenCV function, OpenCV function library copyright belongs
 * to Intel company, will remove these functions in subsequent versions, hereby declare
 */
//
//  Homomorphicfilter
//  同态滤波
//  tony.sheng.tan@gmail.com
//  Created by 谭升 on 14/11/28.
//  Copyright (c) 2014年 谭升. All rights reserved.
//
#include "Homomorphicfilter.h"

void HomorphicFilter(double *filter,int width,int height,double cut_off_frequency,double lambda_l,double lambda_h,double c){
    int center_x=width/2;
    int center_y=height/2;
    double distance;
    double distance_2;
    double cut_off_frequency_2=cut_off_frequency*cut_off_frequency;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++){
            distance=Distance(j, i, center_x, center_y);
            distance_2=distance*distance;
            filter[i*width+j]=(lambda_h-lambda_l)*(1.0-exp(-c*distance_2/cut_off_frequency_2))+lambda_l;
            
        }
}