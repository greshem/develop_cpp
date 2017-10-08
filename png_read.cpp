#include <algorithm>
#include <fstream>
#include <iostream>
#include <iostream> 
#include <iterator>  
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string> 
#include <vector> 
//#include <Baselib.hpp>
//#include <MLmyUnit.hpp>
//#include <QzjUnit.hpp>
//#include <dirent.h>

#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif



#include <png.h>
//2010_09_09 by greshem. 


using namespace std;
int main(int argc, char *argv[])
{

	struct png_stat *h;
	//cout<<sizeof(*h)<<endl;
	return 0;
	
}
#if 0
struct png_stat * png_init(FILE *fp  )
{
	if(fp==NULL)
	{
		return NULL;
	}
	struct png_stat *h;
	int bit_depth, interlace_type;	
	png_uint_32 resx, resy;
	h=(png_stat *)malloc(sizeof(*h));
	memset(h, 0, sizeof(png_stat));	
	h->infile=fp;	
	int unit;

	h->png=png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL ,NULL, NULL);
	if( NULL == h->png)
	{
		die<char>("create read struct  error\n");	
	}
	h->info=png_create_info_struct(h->png);
	if(h->info == NULL)
	{
		die<char>("create info error\n");
	}
	png_init_io(h->png, h->infile);
	png_read_info(h->png, h->info);	
	png_get_IHDR(h->png, h->info, $h->w, &h->h, 
				&bit_depth, &h->color_type, &interlace_type, NULL, NULL);
	png_get_pHYs(h->png, h->info, &resx, &resy, &unit);

	if(PNG_RESOLUTIN_METER==unit)
	{
	
	}


	png_set_packing(h->png);
    if (bit_depth == 16)
        png_set_strip_16(h->png);
    if (h->color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_palette_to_rgb(h->png);
    if (h->color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
        png_set_gray_1_2_4_to_8(h->png);

    if (png_get_bKGD(h->png, h->info, &file_bg)) 
	{
        png_set_background(h->png,file_bg,PNG_BACKGROUND_GAMMA_FILE,1,1.0);
    } else 
	{
        png_set_background(h->png,&my_bg,PNG_BACKGROUND_GAMMA_SCREEN,0,1.0);
    }

   int  number_passes = png_set_interlace_handling(h->png);
    png_read_update_info(h->png, h->info);

    h->color_type = png_get_color_type(h->png, h->info);
    if (debug)
        fprintf(stderr,"png: color_type=%s #2\n",ct[h->color_type]);
    
    char *image = malloc(i->width * i->height * 4);
    
    for (int pass = 0; pass < number_passes-1; pass++) 
	{
        if (debug)
            fprintf(stderr,"png: pass #%d\n",pass);
        for (y = 0; y < i->height; y++) 
		{
            png_bytep row = h->image + y * (h->w) * 4;
            png_read_rows(h->png, &row, NULL, 1);
        }
    }

    return h;
}
#endif
