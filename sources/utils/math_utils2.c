#include "../../includes/cub3D_struct.h"

t_vec2D	add_2d_vec(t_vec2D v1, t_vec2D v2)
{
	t_vec2D	product_vector;

	product_vector.x = v1.x + v2.x;
	product_vector.y = v1.y + v2.y;
	return (product_vector);
}

t_vec2D	subtract_2d_vec(t_vec2D v1, t_vec2D v2)
{
	t_vec2D	result_vector;

	result_vector.x = v1.x - v2.x;
	result_vector.y = v1.y - v2.y;
	return (result_vector);
}

t_vec2D	get_perpendicular_vec(t_vec2D vec)
{
	t_vec2D	perpendicular_vec;

	perpendicular_vec.x = vec.y;
	perpendicular_vec.y = vec.x;
	return (perpendicular_vec);
}

t_vec2D	scalar_mult(t_vec2D vec, double scalar)
{
	t_vec2D	res_scalar_product;

	res_scalar_product.x = vec.x * scalar;
	res_scalar_product.y = vec.y * scalar;
	return (res_scalar_product);
}

int	ft_abs_2_values(int a, int b)
{
	if (a == b)
		return (0);
	else if (a < b)
		return (b - a);
	else
		return (a - b);
}
