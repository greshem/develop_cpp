#include <stdio.h>
#include <string.h>
#include <math.h>
#ifdef WINDOWSCODE
#error "not support widnows now "
#else
#endif

#include <ft2build.h>
#include <locale.h>     /* setlocale() */
#include <stringprep.h>


//#include "qldc.h"

#include FT_FREETYPE_H


#define WIDTH   100
#define HEIGHT  100


//CQlDC mydc;


/* origin is the upper left corner */
unsigned char image[HEIGHT][WIDTH];

/* Replace this function with something useful. */
void draw_bitmap(FT_Bitmap*  bitmap,FT_Int      x,FT_Int      y)
{
  FT_Int  i, j, p, q;
  FT_Int  x_max = x + bitmap->width;
  FT_Int  y_max = y + bitmap->rows;


  for (i = x, p = 0; i < x_max; i++, p++ )
  {
    for (j = y, q = 0; j < y_max; j++, q++ )
    {
      if (i < 0|| j < 0 ||i >= WIDTH || j >= HEIGHT )
        continue;

//      image[j][i] |= bitmap->buffer[q * bitmap->width + p];
		if(bitmap->buffer[q * bitmap->width + p])
//		if(bitmap->buffer[j * bitmap->width + i])
		{
//			mydc.PutPixel(i, j, 100);    
			printf("#");
		}
		else
		{
//			mydc.PutPixel(i, j, 0);    
			printf(".");
		}
    }
	printf("\n");
  }
}


//char text[]={0xe4,0xb8,0xad,0x0a,0x00};
char text[]={'a', 'b','c',0};

int main(int     argc, char**  argv )
{
  FT_Library    library;
  FT_Face       face;
  FT_GlyphSlot  slot;
  FT_Matrix     matrix;                 /* transformation matrix */
  FT_Vector     pen;                    /* untransformed origin  */
  FT_Error      error;


  char*         filename;
  //char*         text;
  double        angle;
  int           target_height;
  int           n, num_chars;

  if(argc != 2)
  {
    fprintf (stderr, "usage: %s font sample-text\n", argv[0] );
    exit(0);
  }

	setlocale (LC_ALL, "");
	//printf(" %s " ,  buff );
	char *p=stringprep_utf8_to_locale(text);
	printf("%s\n", p);


  filename      = "/root/file_type/simsun.ttc";                           /* first argument     */
  //text          = argv[1];                           /* second argument    */
  num_chars     = strlen(text );
  //angle         = (180 / 360 ) * 3.14159 / 2;      /* use 25 degrees     */
  angle         = 0;
  target_height = HEIGHT;

  error = FT_Init_FreeType(&library );              /* initialize library */
  /* error handling omitted */

  error = FT_New_Face(library, filename, 0, &face ); /* create face object */
  /* error handling omitted */

  /* use 50pt at 100dpi */
  error = FT_Set_Char_Size(face, 50 * 64, 0,100, 0 );                /* set character size */
  /* error handling omitted */
  slot = face->glyph;
  /* set up matrix */
  matrix.xx = (FT_Fixed)(cos(angle ) * 0x10000L );
  //matrix.xy = (FT_Fixed)(-sin(angle ) * 0x10000L );
  matrix.xy = (FT_Fixed)(sin(angle ) * 0x10000L );
  matrix.yx = (FT_Fixed)(sin(angle ) * 0x10000L );
  matrix.yy = (FT_Fixed)(cos(angle ) * 0x10000L );

  /* the pen position in 26.6 cartesian space coordinates; */
  /* start at (300,200) relative to the upper left corner  */
  //pen.x = 300 * 64; 图片比较大的时候用， (300,200) 64的乘数需要注意, 和88行对应。 
  //pen.y = (target_height - 200 ) * 64;
  pen.x=1*64;
  pen.y=1*64;
  for (n = 0; n < num_chars; n++ )
  {
	//旋转 
    FT_Set_Transform(face, &matrix, &pen );
    //FT_Set_Transform(face, NULL, &pen );

    /* load glyph image into the slot (erase previous one) */
	//把字形载入进来
    error = FT_Load_Char(face, text[n], FT_LOAD_RENDER );
    if (error )
      continue;                 /* ignore errors */

    /* now, draw to our target surface (convert position) */
    draw_bitmap(&slot->bitmap,slot->bitmap_left,target_height - slot->bitmap_top );

    /* increment pen position */
    pen.x += slot->advance.x;
    pen.y += slot->advance.y;
  }

  FT_Done_Face    (face );
  FT_Done_FreeType(library );
  return 0;
}

