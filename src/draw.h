#ifndef DRAW_H
#define DRAW_H

#define embed __attribute__((always_inline)) inline

extern int width;
extern int height;

embed void put_pixel(uint32_t *buffer, int x, int y, uint32_t color)
{
    if ((x | y) >= 0)
    {
        if (x < width) 
        {
            if (y < height) 
            {
                buffer[y * width + x] = color;
            }
        }
    }
}

#define abs(x) ((x) > 0 ? (x) : -(x))
embed void plot_line(uint32_t *buffer, int x0, int y0, int x1, int y1, uint32_t color)
{
    int dy = abs(y1 - y0);
    int dx = abs(x1 - x0);

    int inc, norm;
    float slope;
    float carry;

    if (dx > dy)
    {
        slope = (float)dy / dx;
        slope = y0 < y1 ? slope : -slope;
        norm = x0 < x1 ? 1 : -1;

        inc = x0; carry = (float)y0;

        for (int i = 0; i < dx; i++)
        {
            put_pixel(buffer, inc, (int)carry, color);
            carry += slope;
            inc += norm;
        }
    }
    else
    {
        slope = (float)dx / dy;
        slope = x0 < x1 ? slope : -slope;
        norm = y0 < y1 ? 1 : -1;

        inc = y0; carry = (float)x0;

        for (int i = 0; i < dy; i++)
        {
            put_pixel(buffer, (int)carry, inc, color);
            carry += slope;
            inc += norm;
        }
    }
}

embed void plot_triangle(uint32_t *buffer, 
                   int x0, int y0, 
                   int x1, int y1,
                   int x2, int y2,
                   uint32_t color)
{
    

    int dy = abs(y2 - y1);
    int dx = abs(x2 - x1);

    int inc, norm;
    float slope;
    float carry;

    if (dx > dy)
    {
        slope = (float)dy / dx;
        slope = y1 < y2 ? slope : -slope;
        norm = x1 < x2 ? 1 : -1;

        inc = x1; carry = (float)y1;

        for (int i = 0; i < dx; i++)
        {
            plot_line(buffer, x0, y0, inc, (int)carry, color);
            carry += slope;
            inc += norm;
        }
    }
    else
    {
        slope = (float)dx / dy;
        slope = x1 < x2 ? slope : -slope;
        norm = y1 < y2 ? 1 : -1;

        inc = y1; carry = (float)x1;

        for (int i = 0; i < dy; i++)
        {
            plot_line(buffer, x0, y0, (int)carry, inc, color);
            carry += slope;
            inc += norm;
        }
    }
}

void clear(uint32_t *buffer, uint32_t color)
{
    for (int i = 0; i < width * height; i++)
        buffer[i] = color;
}

#endif
