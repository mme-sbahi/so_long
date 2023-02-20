#include "so_long.h"

void draw_map_1(t_ptr *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(data->tab[i])
    {
        j = 0;
        x = 0;
        while(data->tab[i][j])
        {
            if (data->tab[i][j] == '1')
            {
                data->img = mlx_xpm_file_to_image(data->mlx,"images/wall.xpm",&data->a,&data->b);
                mlx_put_image_to_window(data->mlx,data->win,data->img,x,y);
            }
            j++;
            x += 40;
        }
        y += 40;
        i++;
    }
}

void draw_map_P(t_ptr *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(data->tab[i])
    {
        j = 0;
        x = 0;
        while(data->tab[i][j])
        {
            if (data->tab[i][j] == 'P')
            {
                data->img = mlx_xpm_file_to_image(data->mlx,"images/Player.xpm",&data->a,&data->b);
                mlx_put_image_to_window(data->mlx,data->win,data->img,x,y);
            }
            j++;
            x += 40;
        }
        y += 40;
        i++;
    }
}
void draw_map_C(t_ptr *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(data->tab[i])
    {
        j = 0;
        x = 0;
        while(data->tab[i][j])
        {
            if (data->tab[i][j] == 'C')
            {
                data->img = mlx_xpm_file_to_image(data->mlx,"images/c.xpm",&data->a,&data->b);
                mlx_put_image_to_window(data->mlx,data->win,data->img,x,y);
            }
            j++;
            x += 40;
        }
        y += 40;
        i++;
    }
}
void draw_map_E(t_ptr *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(data->tab[i])
    {
        j = 0;
        x = 0;
        while(data->tab[i][j])
        {
            if (data->tab[i][j] == 'E')
            {
                data->img = mlx_xpm_file_to_image(data->mlx,"images/exit.xpm",&data->a,&data->b);
                mlx_put_image_to_window(data->mlx,data->win,data->img,x,y);
            }
            j++;
            x += 40;
        }
        y += 40;
        i++;
    }
}
void draw_map_0(t_ptr *data)
{
    int i;
    int j;
    int x;
    int y;
    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while(data->tab[i])
    {
        j = 0;
        x = 0;
        while(data->tab[i][j])
        {
            if (data->tab[i][j] == '0')
            {
                data->img = mlx_xpm_file_to_image(data->mlx,"images/floor.xpm",&data->a,&data->b);
                mlx_put_image_to_window(data->mlx,data->win,data->img,x,y);
            }
            j++;
            x += 40;
        }
        y += 40;
        i++;
    }
}