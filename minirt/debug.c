#include "render.h"

void	print_vec(t_vec vec);
void	print_val(t_scl val);
void	print_lights(t_list *lights);
void	print_obj(t_list *objs);

void	print_data(t_render *data)
{
	t_world	*world = &data->world;
	t_scene	*scene = &data->scene;

	dprintf(2, "--------------- SCENE ----------------\n");
	dprintf(2, "[Camera]\n");
	dprintf(2, "\tfrom ");
	print_vec(scene->cam.from);
	dprintf(2, "\tat ");
	print_vec(scene->cam.at);
	dprintf(2, "\tfov ");
	print_val(scene->cam.fov);
	dprintf(2, "\n");

	dprintf(2, "[Ambient]\n");
	dprintf(2, "\talbedo ");
	print_vec(world->ambient);
	dprintf(2, "\n");

	dprintf(2, "--------------- LIGHT -----------------\n");
	print_lights(world->lights);

	dprintf(2, "--------------- OBJECT ----------------\n");
	print_obj(world->objs);

	dprintf(2, "---------------------------------------\n");
}

void	print_vec(t_vec vec)
{
	dprintf(2, "(%.2f, %.2f, %.2f)\n",
		vec.x, vec.y, vec.z);
}

void	print_val(t_scl val)
{
	dprintf(2, "(%.2f)\n", val);
}

void	print_sphere(t_obj *obj);
void	print_cylinder(t_obj *obj);
void	print_plane(t_obj *obj);

void	print_obj(t_list *objs)
{
	t_name	name;
	t_txtr	*txtr;
	
	while (objs)
	{
		name = ((t_obj *)objs->content)->name;
		txtr = &((t_obj *)objs->content)->txtr;
		
		if (name == SPHERE)
			print_sphere(objs->content);
		else if (name == CYLNDR)
			print_cylinder(objs->content);
		else
			print_plane(objs->content);
		dprintf(2, "\tcolor ");
		print_vec(txtr->albedo1);

		if (txtr->scale)
		{
			dprintf(2, "\tcheckr color ");
			print_vec(txtr->albedo2);
			dprintf(2, "\tchecker scale ");
			print_val(txtr->scale);
		}

		dprintf(2, "\n");
		objs = objs->next;
	}
}

void	print_sphere(t_obj *obj)
{
	t_value	*val = &obj->val;

	dprintf(2, "[Sphere]\n");
	dprintf(2, "\tcenter ");
	print_vec(val->cir.center);
	dprintf(2, "\tradius ");
	print_val(val->cir.radius);
}

void	print_cylinder(t_obj *obj)
{
	t_value	*val = &obj->val;

	dprintf(2, "[Cylinder]\n");
	dprintf(2, "\tcenter ");
	print_vec(val->cir.center);
	dprintf(2, "\tradius ");
	print_val(val->cir.radius);
	dprintf(2, "\theght ");
	print_val(val->cyl.height);
	dprintf(2, "\taxis ");
	print_vec(val->cyl.axis);
}

void	print_plane(t_obj *obj)
{
	t_value	*val = &obj->val;

	dprintf(2, "[Plane]\n");
	dprintf(2, "\tpoint ");
	print_vec(val->sqr.point);
	dprintf(2, "\tnormal ");
	print_vec(val->sqr.normal);
}

void	print_lights(t_list *lights)
{
	t_light *light;

	while (lights)
	{
		light = lights->content;

		dprintf(2, "[Light]\n");
		dprintf(2, "\tpoint ");
		print_vec(light->point);
		dprintf(2, "\tcolor ");
		print_vec(light->albedo);

		dprintf(2, "\n");
		lights = lights->next;
	}
}
