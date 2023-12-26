#include "../../includes/cub3D_struct.h"

double	vec_length(t_vec2D vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

double	dot_prod(t_vec2D vec1, t_vec2D vec2)
{
	return (vec1.x * vec2.x + vec1.y * vec2.y);
}

int	color_from_texture(t_cub3D *data, int dir, double xper, int y)
{
	t_texture	texture;
	int			x;

	texture = data->wall_textures[dir];
	if (y > texture.img_height)
		y = texture.img_height;
	if (y < 0)
		y = 0;
	x = texture.img_width * xper;
	if (x > texture.img_width)
		x = texture.img_width;
	if (x < 0)
		x = 0;
	return (((int *)texture.addr)[y * (texture.line_len / sizeof(int)) + x]);
}

int	ceiling_floor_color(t_cub3D *data, double xper, double yper, int type)
{
	int			x;
	int			y;
	t_texture	tex;

	tex = data->wall_textures[type];
	if (tex.img)
	{
		y = tex.img_height * yper;
		x = tex.img_width * xper;
		return (((int *)tex.addr)[y * \
		(tex.line_len / sizeof(int)) + x]);
	}
	return (data->background_colors[type - 6]);
}
