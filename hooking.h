#pragma once// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
bool in_area(fvector2d target, fvector2d pos, fvector2d size)// payson1337 - github.com/paysonism
{// payson1337 - github.com/paysonism
	if (target.x > pos.x && target.y > pos.y)// payson1337 - github.com/paysonism
		if (target.x < pos.x + size.x && target.y < pos.y + size.y)// payson1337 - github.com/paysonism
			return true;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	return false;// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
namespace menu {// payson1337 - github.com/paysonism
	fvector2d pos = { 35, 35 };// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	static void run(ucanvas* canvas) {// payson1337 - github.com/paysonism
		if (render::show_menu) {// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			ZeroGUI::SetupCanvas(canvas);// payson1337 - github.com/paysonism
			ZeroGUI::Input::Handle();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			float width = ((double)canvas->clip_x());// payson1337 - github.com/paysonism
			float height = ((double)canvas->clip_y());// payson1337 - github.com/paysonism
			if (ZeroGUI::Window("SubZeroFN Free Internal v2 - discord.gg/subz", &pos, fvector2d{ 450.0f, 500.0f }, render::show_menu, width, height)) {// payson1337 - github.com/paysonism
				ZeroGUI::Draw_Cursor(render::draw_cursor);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				const char* tabNames[] = { "Aim", "Bones", "Player", "Radar", "Exploits", "World", "Misc" };// payson1337 - github.com/paysonism
				static int tab = 0;// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				for (int i = 0; i < sizeof(tabNames) / sizeof(tabNames[0]); i++) {// payson1337 - github.com/paysonism
					if (ZeroGUI::ButtonTab(tabNames[i], fvector2d{ 100, 25 }, tab == i)) {// payson1337 - github.com/paysonism
						tab = i;// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				if (tab == 0)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Enable Aimbot", &settings::aimbot::mouse);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
											//ZeroGUI::Checkbox("Enable Memory", &settings::aimbot::memory);// payson1337 - github.com/paysonism
					if (settings::aimbot::mouse)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Mouse Smoothing", &settings::aimbot::mouse_speed, 1, 25);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Vis Check", &settings::aimbot::visible_only);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Target Line", &settings::aimbot::target_line);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Show FOV", &settings::aimbot::show_fov);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("FOV", &settings::aimbot::field_of_view, 1, 100);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					//if (settings::aimbot::memory)// payson1337 - github.com/paysonism
					//{// payson1337 - github.com/paysonism
					//	ZeroGUI::Checkbox("Interpolate", &settings::aimbot::interpolate);// payson1337 - github.com/paysonism
					//	ZeroGUI::Checkbox("Constant", &settings::aimbot::constant);// payson1337 - github.com/paysonism
					//	ZeroGUI::SliderFloat("Interp Speed", &settings::aimbot::interpolate_speed, 1, 25);// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
					//}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 1)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Head", &settings::bones::head);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Neck", &settings::bones::neck);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Torso", &settings::bones::torso);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Pelvis", &settings::bones::pelvis);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 2)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Enable", &settings::player::enable);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::player::enable)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Box", &settings::player::normal_box);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Cornered Box", &settings::player::cornered_box);// payson1337 - github.com/paysonism
						if (!settings::style::performance) {// payson1337 - github.com/paysonism
							ZeroGUI::Checkbox("Skeleton", &settings::player::skeleton);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Distance", &settings::player::display_distance);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Snaplines", &settings::player::snapline);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Weapon", &settings::player::active_weapon);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Name", &settings::player::player_name);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Eyes", &settings::player::eyes);// payson1337 - github.com/paysonism
						//	ZeroGUI::SliderFloat("Render Distance", &settings::player::max_distance, 5, 900);// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 3)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Enable", &settings::radar::enable);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::radar::enable)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Show Line Of Sight", &settings::radar::show_line_of_sight);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Circle", &settings::radar::useless_circle);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Players", &settings::radar::players);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Containers", &settings::radar::containers);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Pickups", &settings::radar::pickups);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Vehicles", &settings::radar::vehicles);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Range Distance", &settings::radar::range, 5, 450);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Position X", &settings::radar::positionx, 0, 500);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Position Y", &settings::radar::positiony, 0, 500);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Size", &settings::radar::size, 0, 300);// payson1337 - github.com/paysonism
						// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 4)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Bullet TP", &settings::aimbot::bulletp);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("FOV Changer", &settings::miscellaneous::fovchanger);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("No Recoil", &settings::miscellaneous::norecoil);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Car Fly", &settings::miscellaneous::vehiclefly);// payson1337 - github.com/paysonism
					if (settings::miscellaneous::fovchanger)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("FOV Value", &settings::miscellaneous::fovslider, 0, 180);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					if (settings::miscellaneous::vehiclefly)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Car Fly Speed", &settings::miscellaneous::vehicle_flight_speed, 0, 600);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 5)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Enable", &settings::miscactors::enable);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::miscactors::enable)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Display Distance", &settings::miscactors::display_distance);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Vehicles", &settings::miscactors::vehicles);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Rifts", &settings::miscactors::rifts);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Flags", &settings::miscactors::flags);// payson1337 - github.com/paysonism
						ZeroGUI::Checkbox("Traps", &settings::miscactors::traps);// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Render Distance", &settings::miscactors::max_distance, 0, 450);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				else if (tab == 6)// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					ZeroGUI::NextColumn(130.0f);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Outlined Text", &settings::style::text_outlined);// payson1337 - github.com/paysonism
					ZeroGUI::Checkbox("Outlined ESP", &render::outline);// payson1337 - github.com/paysonism
					if (render::outline) {// payson1337 - github.com/paysonism
						ZeroGUI::SliderFloat("Outline Thickness", &render::outlinethickness, 0, 10);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					ZeroGUI::SliderFloat("ESP Thickness", &render::linethickness, 0, 10);// payson1337 - github.com/paysonism
					//ZeroGUI::Checkbox("Draw Cursor", &render::draw_cursor);// payson1337 - github.com/paysonism
					ZeroGUI::Text("SubZeroFN Free Internal - Made By Payson");// payson1337 - github.com/paysonism
					ZeroGUI::Text("discord.gg/subz - github.com/paysonism");// payson1337 - github.com/paysonism
					ZeroGUI::Text("Source: github.com/paysonism/subzero-free-int");// payson1337 - github.com/paysonism
					ZeroGUI::Text("Menu Key: INSERT");// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
#define M_PI   3.14159265358979323846264338327950288// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
float degree_to_radian(float degree) {// payson1337 - github.com/paysonism
	return degree * (M_PI / 180);// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
void angle_rotation(const frotator& angles, fvector* forward)// payson1337 - github.com/paysonism
{// payson1337 - github.com/paysonism
	float	sp, sy, cp, cy;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	sy = sin(degree_to_radian(angles.yaw));// payson1337 - github.com/paysonism
	cy = cos(degree_to_radian(angles.yaw));// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	sp = sin(degree_to_radian(angles.pitch));// payson1337 - github.com/paysonism
	cp = cos(degree_to_radian(angles.pitch));// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	forward->x = cp * cy;// payson1337 - github.com/paysonism
	forward->y = cp * sy;// payson1337 - github.com/paysonism
	forward->z = -sp;// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
namespace fortnite {// payson1337 - github.com/paysonism
	namespace temp {// payson1337 - github.com/paysonism
		bool silent_active = false;// payson1337 - github.com/paysonism
		frotator silent_rotation = frotator();// payson1337 - github.com/paysonism
		bool sticky_silent_active = false;// payson1337 - github.com/paysonism
		frotator sticky_silent_rotation = frotator();// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
	bool visible;// payson1337 - github.com/paysonism
	namespace radar {// payson1337 - github.com/paysonism
		fvector2d position, size;// payson1337 - github.com/paysonism
		fvector camera_location;// payson1337 - github.com/paysonism
		frotator camera_rotation;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		void range(double* x, double* y, double range) {// payson1337 - github.com/paysonism
			if (defines::math->abs((*x)) > range || defines::math->abs((*y)) > range) {// payson1337 - github.com/paysonism
				if ((*y) > (*x)) {// payson1337 - github.com/paysonism
					if ((*y) > -(*x)) {// payson1337 - github.com/paysonism
						(*x) = range * (*x) / (*y);// payson1337 - github.com/paysonism
						(*y) = range;// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else {// payson1337 - github.com/paysonism
						(*y) = -range * (*y) / (*x);// payson1337 - github.com/paysonism
						(*x) = -range;// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else {// payson1337 - github.com/paysonism
					if ((*y) > -(*x)) {// payson1337 - github.com/paysonism
						(*y) = range * (*y) / (*x);// payson1337 - github.com/paysonism
						(*x) = range;// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else {// payson1337 - github.com/paysonism
						(*x) = -range * (*x) / (*y);// payson1337 - github.com/paysonism
						(*y) = -range;// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		void rotate_point(fvector2d* screen, fvector origin, fvector camera_location, frotator camera_rotation) {// payson1337 - github.com/paysonism
			auto yaw = camera_rotation.yaw * 3.1415927 / 180;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double dx = origin.x - camera_location.x;// payson1337 - github.com/paysonism
			double dy = origin.y - camera_location.y;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double fsin_yaw = defines::math->sin(yaw);// payson1337 - github.com/paysonism
			double fminus_cos_yaw = -defines::math->cos(yaw);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double x = -(dy * fminus_cos_yaw + dx * fsin_yaw);// payson1337 - github.com/paysonism
			double y = dx * fminus_cos_yaw - dy * fsin_yaw;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double range_value = settings::radar::range * 1000;// payson1337 - github.com/paysonism
			range(&x, &y, range_value);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto DrawPos = radar::position;// payson1337 - github.com/paysonism
			auto DrawSize = radar::size;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			int rad_x = (int)DrawPos.x;// payson1337 - github.com/paysonism
			int rad_y = (int)DrawPos.y;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double r_siz_x = DrawSize.x;// payson1337 - github.com/paysonism
			double r_siz_y = DrawSize.y;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			int x_max = (int)r_siz_x + rad_x - 5;// payson1337 - github.com/paysonism
			int y_max = (int)r_siz_y + rad_y - 5;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			double out_screen_x = rad_x + ((int)r_siz_x / 2 + int(x / range_value * r_siz_x));// payson1337 - github.com/paysonism
			double out_screen_y = rad_y + ((int)r_siz_y / 2 + int(y / range_value * r_siz_y));// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (out_screen_x > x_max)// payson1337 - github.com/paysonism
				out_screen_x = x_max;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (out_screen_x < rad_x)// payson1337 - github.com/paysonism
				out_screen_x = rad_x;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (out_screen_y > y_max)// payson1337 - github.com/paysonism
				out_screen_y = y_max;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (out_screen_y < rad_y)// payson1337 - github.com/paysonism
				out_screen_y = rad_y;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			*screen = fvector2d(out_screen_x, out_screen_y);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		void add_to_radar(fvector world_location, flinearcolor color) {// payson1337 - github.com/paysonism
			fvector2d screen;// payson1337 - github.com/paysonism
			rotate_point(&screen, world_location, radar::camera_location, radar::camera_rotation);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			render::filled_box(screen, fvector2d(4, 4), color);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		void radar_initialize(fvector2d position, fvector2d size, fvector camera_location, frotator camera_rotation) {// payson1337 - github.com/paysonism
			radar::position = position;// payson1337 - github.com/paysonism
			radar::size = size;// payson1337 - github.com/paysonism
			radar::camera_location = camera_location;// payson1337 - github.com/paysonism
			radar::camera_rotation = camera_rotation;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			render::filled_box(position, size, flinearcolor(0.025f, 0.025f, 0.025f, 1.f));// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (settings::radar::useless_circle) {// payson1337 - github.com/paysonism
				render::circle(fvector2d(position.x + size.x / 2, position.y + size.y / 2), size.x / 2, 100, flinearcolor(1.f, 1.f, 1.f, 1.f));// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::radar::show_line_of_sight) {// payson1337 - github.com/paysonism
				render::line(fvector2d(position.x + size.x / 2, position.y + size.y), fvector2d(position.x + size.x / 2, position.y + size.y / 2), flinearcolor(1.f, 1.f, 1.f, 1.f), 1.f);// payson1337 - github.com/paysonism
				render::line(fvector2d(position.x + size.x / 2, position.y + size.y / 2), fvector2d(position.x, position.y), flinearcolor(1.f, 1.f, 1.f, 1.f), 1.f);// payson1337 - github.com/paysonism
				render::line(fvector2d(position.x + size.x / 2, position.y + size.y / 2), fvector2d(position.x + size.x, position.y), flinearcolor(1.f, 1.f, 1.f, 1.f), 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	void set_aim_mouse(aplayercontroller* controller, fvector aim_location, float width, float height, float smooth) {// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		float ScreenCenterX = (width / 2);// payson1337 - github.com/paysonism
		float ScreenCenterY = (height / 2);// payson1337 - github.com/paysonism
		float TargetX = 0;// payson1337 - github.com/paysonism
		float TargetY = 0;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		auto aim_screen = fvector2d();// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (controller->w2s(aim_location, &aim_screen) && aim_screen) {// payson1337 - github.com/paysonism
			if (aim_screen.x != 0) {// payson1337 - github.com/paysonism
				if (aim_screen.x > ScreenCenterX) {// payson1337 - github.com/paysonism
					TargetX = -(ScreenCenterX - aim_screen.x);// payson1337 - github.com/paysonism
					TargetX /= smooth;// payson1337 - github.com/paysonism
					if (TargetX + ScreenCenterX > ScreenCenterX * 2) TargetX = 0;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				if (aim_screen.x < ScreenCenterX) {// payson1337 - github.com/paysonism
					TargetX = aim_screen.x - ScreenCenterX;// payson1337 - github.com/paysonism
					TargetX /= smooth;// payson1337 - github.com/paysonism
					if (TargetX + ScreenCenterX < 0) TargetX = 0;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (aim_screen.y != 0) {// payson1337 - github.com/paysonism
				if (aim_screen.y > ScreenCenterY) {// payson1337 - github.com/paysonism
					TargetY = -(ScreenCenterY - aim_screen.y);// payson1337 - github.com/paysonism
					TargetY /= smooth;// payson1337 - github.com/paysonism
					if (TargetY + ScreenCenterY > ScreenCenterY * 2) TargetY = 0;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
				if (aim_screen.y < ScreenCenterY) {// payson1337 - github.com/paysonism
					TargetY = aim_screen.y - ScreenCenterY;// payson1337 - github.com/paysonism
					TargetY /= smooth;// payson1337 - github.com/paysonism
					if (TargetY + ScreenCenterY < 0) TargetY = 0;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			IFH(mouse_event)(MOUSEEVENTF_MOVE, static_cast<DWORD>(TargetX), static_cast<DWORD>(TargetY), NULL, NULL);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	void set_aim(uworld* world, aplayercontroller* controller, fvector camera_location, frotator camera_rotation, fvector aim_location, bool interpolate, bool constant, double speed) {// payson1337 - github.com/paysonism
		auto aim_rotation = defines::math->find_look_at_rotation(camera_location, aim_location);// payson1337 - github.com/paysonism
		auto world_delta_seconds = defines::game_statics->get_world_delta_seconds(world);// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		auto result = aim_rotation;// payson1337 - github.com/paysonism
		if (interpolate) {// payson1337 - github.com/paysonism
			if (constant)// payson1337 - github.com/paysonism
				result = defines::math->interp_to_constant(camera_rotation, aim_rotation, world_delta_seconds, speed);// payson1337 - github.com/paysonism
			else// payson1337 - github.com/paysonism
				result = defines::math->interp_to(camera_rotation, aim_rotation, world_delta_seconds, speed);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		result.pitch = (result.pitch - camera_rotation.pitch) / controller->input_pitch_scale();// payson1337 - github.com/paysonism
		result.yaw = (result.yaw - camera_rotation.yaw) / controller->input_yaw_scale();// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		controller->add_pitch_input((float)result.pitch);// payson1337 - github.com/paysonism
		controller->add_yaw_input((float)result.yaw);// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	fvector bottom, bottom_2, head, head_2, neck, chest, pelvis, rshoulder, relbow, rhand, rthigh, rknee, rfoot, rfootout, lshoulder, lelbow, lhand, lthigh, lknee, lfoot, lfootout;// payson1337 - github.com/paysonism
	fvector2d s_bottom, s_bottom_2, s_head, s_head_2, s_neck, s_chest, s_pelvis, s_rshoulder, s_relbow, s_rhand, s_rthigh, s_rknee, s_rfoot, s_rfootout, s_lshoulder, s_lelbow, s_lhand, s_lthigh, s_lknee, s_lfoot, s_lfootout;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	bool get_performance_bones(aplayercontroller* controller, mesh* mesh) {// payson1337 - github.com/paysonism
		bool success = true;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		bottom = mesh->get_bone_location(0);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(bottom, &s_bottom)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
		head = mesh->get_bone_location(68);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(head, &s_head)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (!s_bottom || !s_head) // payson1337 - github.com/paysonism
			return false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		return success;// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	bool get_all_bones(aplayercontroller* controller, mesh* mesh) {// payson1337 - github.com/paysonism
		bool success = true;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		bottom = mesh->get_bone_location(0);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(bottom, &s_bottom)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		bottom_2 = bottom; bottom_2.z -= 10;// payson1337 - github.com/paysonism
		if (success && !controller->w2s(bottom_2, &s_bottom_2)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		head = mesh->get_bone_location(68);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(head, &s_head)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		head_2 = head; head_2.z += 13;// payson1337 - github.com/paysonism
		if (success && !controller->w2s(head_2, &s_head_2)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		neck = mesh->get_bone_location(67);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(neck, &s_neck)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		chest = mesh->get_bone_location(7); chest.z += 7;// payson1337 - github.com/paysonism
		if (success && !controller->w2s(chest, &s_chest)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		pelvis = mesh->get_bone_location(2);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(pelvis, &s_pelvis)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rshoulder = mesh->get_bone_location(38);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rshoulder, &s_rshoulder)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		relbow = mesh->get_bone_location(39);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(relbow, &s_relbow)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rhand = mesh->get_bone_location(40);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rhand, &s_rhand)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rthigh = mesh->get_bone_location(78);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rthigh, &s_rthigh)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rknee = mesh->get_bone_location(79);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rknee, &s_rknee)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rfoot = mesh->get_bone_location(82);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rfoot, &s_rfoot)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		rfootout = mesh->get_bone_location(83);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(rfootout, &s_rfootout)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lshoulder = mesh->get_bone_location(9);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lshoulder, &s_lshoulder)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lelbow = mesh->get_bone_location(10);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lelbow, &s_lelbow)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lhand = mesh->get_bone_location(11);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lhand, &s_lhand)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lthigh = mesh->get_bone_location(71);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lthigh, &s_lthigh)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lknee = mesh->get_bone_location(72);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lknee, &s_lknee)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lfoot = mesh->get_bone_location(75);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lfoot, &s_lfoot)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		lfootout = mesh->get_bone_location(76);// payson1337 - github.com/paysonism
		if (success && !controller->w2s(lfootout, &s_lfootout)) success = false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (!s_bottom || !s_head || !s_neck || !s_chest || !s_rshoulder || !s_relbow || !s_rhand || !s_lshoulder || !s_lelbow || !s_lhand || !s_rthigh || !s_rknee || !s_rfoot || !s_rfootout || !s_lthigh || !s_lknee || !s_lfoot || !s_lfootout)// payson1337 - github.com/paysonism
			return false;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		return success;// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
namespace essential_hooks {// payson1337 - github.com/paysonism
	fvector location_o = fvector();// payson1337 - github.com/paysonism
	frotator rotation_o = frotator();// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	ulocalplayer* local_player_old = 0;// payson1337 - github.com/paysonism
	aplayercontroller* player_controller_old = 0;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	using get_view_point_sim = void(*)(ulocalplayer* local_player, fminimalviewinfo* out_viewinfo, BYTE stereo_pass);// payson1337 - github.com/paysonism
	get_view_point_sim get_view_point_o = 0;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	void get_view_point(ulocalplayer* local_player, fminimalviewinfo* out_viewinfo, BYTE stereo_pass) {// payson1337 - github.com/paysonism
		get_view_point_o(local_player, out_viewinfo, stereo_pass);// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (fortnite::temp::silent_active) {// payson1337 - github.com/paysonism
			out_viewinfo->location = location_o;// payson1337 - github.com/paysonism
			out_viewinfo->rotation = rotation_o;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (fortnite::temp::sticky_silent_active) {// payson1337 - github.com/paysonism
			out_viewinfo->location = location_o;// payson1337 - github.com/paysonism
			out_viewinfo->location.z += 40;// payson1337 - github.com/paysonism
			out_viewinfo->rotation = fortnite::temp::sticky_silent_rotation;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (settings::exploits::fov_changer)// payson1337 - github.com/paysonism
			out_viewinfo->fov = settings::exploits::fov_value;// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	using get_player_view_point_sim = void(*)(aplayercontroller* controller, fvector* location, frotator* rotation);// payson1337 - github.com/paysonism
	get_player_view_point_sim get_player_view_point_o = 0;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	void get_player_view_point(aplayercontroller* controller, fvector* location, frotator* rotation) {// payson1337 - github.com/paysonism
		get_player_view_point_o(controller, location, rotation);// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		location_o = *location;// payson1337 - github.com/paysonism
		rotation_o = *rotation;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (fortnite::temp::silent_active) {// payson1337 - github.com/paysonism
			*rotation = fortnite::temp::silent_rotation;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (fortnite::temp::sticky_silent_active) {// payson1337 - github.com/paysonism
			*rotation = fortnite::temp::sticky_silent_rotation;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	void run(aplayercontroller* controller, ulocalplayer* local_player) {// payson1337 - github.com/paysonism
		if (local_player != essential_hooks::local_player_old) {// payson1337 - github.com/paysonism
			//essential_hooks::get_view_point_o = vmt<decltype(essential_hooks::get_view_point_o)>(std::uintptr_t(local_player), std::uintptr_t(essential_hooks::get_view_point), 0x58);// payson1337 - github.com/paysonism
			void** LocalPlayer_VTable = *(void***)(local_player);// payson1337 - github.com/paysonism
			DWORD OldProtection;// payson1337 - github.com/paysonism
			(VirtualProtect)(&LocalPlayer_VTable[88], 8, PAGE_EXECUTE_READWRITE, &OldProtection);// payson1337 - github.com/paysonism
			essential_hooks::get_view_point_o = decltype(essential_hooks::get_view_point_o)(LocalPlayer_VTable[88]);// payson1337 - github.com/paysonism
			LocalPlayer_VTable[88] = &essential_hooks::get_view_point;// payson1337 - github.com/paysonism
			(VirtualProtect)(&LocalPlayer_VTable[88], 8, OldProtection, &OldProtection);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			essential_hooks::local_player_old = local_player;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (controller != essential_hooks::player_controller_old) {// payson1337 - github.com/paysonism
			//essential_hooks::get_player_view_point_o = vmt<decltype(essential_hooks::get_player_view_point_o)>(std::uintptr_t(controller), std::uintptr_t(essential_hooks::get_player_view_point), 0x7E8);// payson1337 - github.com/paysonism
			void** PlayerController_VTable = *(void***)(controller);// payson1337 - github.com/paysonism
			DWORD OldProtection;// payson1337 - github.com/paysonism
			(VirtualProtect)(&PlayerController_VTable[245], 8, PAGE_EXECUTE_READWRITE, &OldProtection);// payson1337 - github.com/paysonism
			essential_hooks::get_player_view_point_o = decltype(essential_hooks::get_player_view_point_o)(PlayerController_VTable[245]);// payson1337 - github.com/paysonism
			PlayerController_VTable[245] = &essential_hooks::get_player_view_point;// payson1337 - github.com/paysonism
			(VirtualProtect)(&PlayerController_VTable[245], 8, OldProtection, &OldProtection);// payson1337 - github.com/paysonism
			essential_hooks::player_controller_old = controller;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
void subzero_load(ugameviewportclient* viewport, ucanvas* canvas) {// payson1337 - github.com/paysonism
	auto screen_size = fvector2d((double)canvas->clip_x(), (double)canvas->clip_y());// payson1337 - github.com/paysonism
	auto center = fvector2d((double)screen_size.x / 2, (double)screen_size.y / 2);// payson1337 - github.com/paysonism
	bool player_silent = false;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto world = viewport->get_world();// payson1337 - github.com/paysonism
	if (!world) return;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto game_instance = defines::game_statics->get_game_instance(world);// payson1337 - github.com/paysonism
	if (!game_instance) return;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto local_player = game_instance->get_local_players()[0];// payson1337 - github.com/paysonism
	if (!game_instance) return;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto controller = defines::game_statics->get_player_controller(world, std::int32_t(0));// payson1337 - github.com/paysonism
	if (!controller) return;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto camera_manager = defines::game_statics->get_player_camera_manager(world, std::int32_t(0));// payson1337 - github.com/paysonism
	if (!camera_manager) return;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	if (settings::exploits::enable_hooks) {// payson1337 - github.com/paysonism
		essential_hooks::run(controller, local_player);// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	render::world = world;// payson1337 - github.com/paysonism
	render::canvas = canvas;// payson1337 - github.com/paysonism
	render::controller = controller;// payson1337 - github.com/paysonism
	render::screen_center = center;// payson1337 - github.com/paysonism
	render::screen_size = screen_size;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	if (render::is_insert_clicked()) render::show_menu = !render::show_menu;// payson1337 - github.com/paysonism
	menu::run(canvas);// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	render::text(L"SubZeroFN Free Internal v2", fvector2d(105, 25), flinearcolor(1.f, 0.f, 1.f, 1.f), true, true, true);// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto camera_location = camera_manager->get_camera_location();// payson1337 - github.com/paysonism
	auto camera_rotation = camera_manager->get_camera_rotation();// payson1337 - github.com/paysonism
	auto camera_fov = camera_manager->get_fov_angle();// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto radius = (settings::aimbot::field_of_view * center.x / (double)camera_fov) / 2; // payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	auto local_pawn_holding_pickaxe = false;// payson1337 - github.com/paysonism
	auto local_pawn = controller->get_pawn();// payson1337 - github.com/paysonism
	auto local_team = (char)6969;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	if (settings::miscellaneous::fovchanger) {// payson1337 - github.com/paysonism
		if (local_pawn) {// payson1337 - github.com/paysonism
			controller->fov(settings::miscellaneous::fovslider);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::radar::enable) {// payson1337 - github.com/paysonism
		fortnite::radar::radar_initialize(fvector2d(settings::radar::positionx, settings::radar::positiony), fvector2d(settings::radar::size, settings::radar::size), camera_location, camera_rotation);// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscellaneous::norecoil) {// payson1337 - github.com/paysonism
		*(float*)(controller + 0x64) = -1;// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscellaneous::vehiclefly) {// payson1337 - github.com/paysonism
		if (local_pawn)// payson1337 - github.com/paysonism
		{// payson1337 - github.com/paysonism
			auto current_vehicle = *(afortvehicle**)(local_pawn + 0x25b8);// payson1337 - github.com/paysonism
			if (current_vehicle && local_pawn) {// payson1337 - github.com/paysonism
				auto current_location = current_vehicle->get_actor_location();// payson1337 - github.com/paysonism
				auto current_rotation = camera_rotation;// payson1337 - github.com/paysonism
				if (controller->is_key_down(defines::W)) {// payson1337 - github.com/paysonism
					current_location.x = current_location.x + settings::miscellaneous::vehicle_flight_speed;// payson1337 - github.com/paysonism
					current_vehicle->k2_teleport_to(current_location, current_rotation);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				if (controller->is_key_down(defines::A)) {// payson1337 - github.com/paysonism
					current_location.y = current_location.y + settings::miscellaneous::vehicle_flight_speed;// payson1337 - github.com/paysonism
					current_vehicle->k2_teleport_to(current_location, current_rotation);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				if (controller->is_key_down(defines::S)) {// payson1337 - github.com/paysonism
					current_location.x = current_location.x - settings::miscellaneous::vehicle_flight_speed;// payson1337 - github.com/paysonism
					current_vehicle->k2_teleport_to(current_location, current_rotation);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				if (controller->is_key_down(defines::D)) {// payson1337 - github.com/paysonism
					current_location.y = current_location.y - settings::miscellaneous::vehicle_flight_speed;// payson1337 - github.com/paysonism
					current_vehicle->k2_teleport_to(current_location, current_rotation);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				if (controller->is_key_down(defines::space)) {// payson1337 - github.com/paysonism
					current_location.z = current_location.z + settings::miscellaneous::vehicle_flight_speed;// payson1337 - github.com/paysonism
					current_vehicle->k2_teleport_to(current_location, current_rotation);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::player::enable) {// payson1337 - github.com/paysonism
		double closest_distance = DBL_MAX;// payson1337 - github.com/paysonism
		player_pawn* target_player = 0;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		tarray<uobject*> player_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_player_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < player_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!player_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto player = (player_pawn*)player_array[i];// payson1337 - github.com/paysonism
			if (player == local_pawn) continue;// payson1337 - github.com/paysonism
			if (!player) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (player->is_dead()) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto object_name = defines::system->get_object_name(player);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (!defines::string->contains(object_name.c_str(), L"PlayerPawn", false, false)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			bool teammate = player->get_team() == local_team;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto esp_color = flinearcolor(1.f, 1.f, 1.f, 1.f);// payson1337 - github.com/paysonism
			auto black_color = flinearcolor(0.f, 0.f, 0.f, 1.f);// payson1337 - github.com/paysonism
			if (teammate)// payson1337 - github.com/paysonism
				esp_color = flinearcolor(0.2f, 1.f, 0.2f, 1.f);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto world_location = player->get_actor_location();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (settings::radar::enable && settings::radar::players) {// payson1337 - github.com/paysonism
				fortnite::radar::add_to_radar(world_location, esp_color);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			auto max_distance = settings::player::max_distance;// payson1337 - github.com/paysonism
			double distance = defines::math->vector_distance(world_location, camera_location) * 0.01;// payson1337 - github.com/paysonism
			if (distance > max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			bool visible = player->was_recently_rendered(0.f);// payson1337 - github.com/paysonism
			if (visible) {// payson1337 - github.com/paysonism
				fortnite::visible = true;// payson1337 - github.com/paysonism
				esp_color = flinearcolor(0.2f, 1.f, 0.2f, 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			else {// payson1337 - github.com/paysonism
				fortnite::visible = false;// payson1337 - github.com/paysonism
				esp_color = flinearcolor(1.0f, 0.2f, 0.2f, 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			auto mesh = player->get_pawn_mesh();// payson1337 - github.com/paysonism
			if (!mesh) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (!settings::style::performance) {// payson1337 - github.com/paysonism
				if (!fortnite::get_all_bones(controller, mesh)) continue;// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			else {// payson1337 - github.com/paysonism
				if (!fortnite::get_performance_bones(controller, mesh)) continue;// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			if (settings::style::performance) {// payson1337 - github.com/paysonism
				if (!in_area(fortnite::s_bottom, fvector2d(50, 50), fvector2d(screen_size.x - (50 * 2), screen_size.y - (50 * 2)))) continue;// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::skeleton) {// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_head, fortnite::s_neck, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_neck, fortnite::s_chest, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_chest, fortnite::s_pelvis, esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_chest, fortnite::s_rshoulder, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_rshoulder, fortnite::s_relbow, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_relbow, fortnite::s_rhand, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_pelvis, fortnite::s_rthigh, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_rthigh, fortnite::s_rknee, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_rknee, fortnite::s_rfoot, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_rfoot, fortnite::s_rfootout, esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_chest, fortnite::s_lshoulder, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_lshoulder, fortnite::s_lelbow, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_lelbow, fortnite::s_lhand, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_pelvis, fortnite::s_lthigh, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_lthigh, fortnite::s_lknee, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_lknee, fortnite::s_lfoot, esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fortnite::s_lfoot, fortnite::s_lfootout, esp_color, 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			auto most_left = DBL_MAX;// payson1337 - github.com/paysonism
			auto most_right = DBL_MIN;// payson1337 - github.com/paysonism
			auto most_top = DBL_MAX;// payson1337 - github.com/paysonism
			auto most_bottom = DBL_MIN;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (!settings::style::performance) {// payson1337 - github.com/paysonism
				fvector2d bones_to_check[] = { fortnite::s_bottom, fortnite::s_head, fortnite::s_head_2, fortnite::s_neck, fortnite::s_chest, fortnite::s_pelvis, fortnite::s_rshoulder, fortnite::s_relbow, fortnite::s_rhand, fortnite::s_rthigh, fortnite::s_rknee, fortnite::s_rfoot, fortnite::s_rfootout, fortnite::s_lshoulder, fortnite::s_lelbow,fortnite::s_lhand, fortnite::s_lthigh, fortnite::s_lknee, fortnite::s_lfoot, fortnite::s_lfootout };// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				for (int i = 0; i < 20; i++) {// payson1337 - github.com/paysonism
					auto bone = bones_to_check[i];// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.x < most_left)// payson1337 - github.com/paysonism
						most_left = bone.x;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.x > most_right)// payson1337 - github.com/paysonism
						most_right = bone.x;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.y < most_top)// payson1337 - github.com/paysonism
						most_top = bone.y;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.y > most_bottom)// payson1337 - github.com/paysonism
						most_bottom = bone.y;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			else {// payson1337 - github.com/paysonism
				fvector2d bones_to_check[] = { fortnite::s_bottom, fortnite::s_head };// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				for (int i = 0; i < 2; i++) {// payson1337 - github.com/paysonism
					auto bone = bones_to_check[i];// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.x < most_left)// payson1337 - github.com/paysonism
						most_left = bone.x;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.x > most_right)// payson1337 - github.com/paysonism
						most_right = bone.x;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.y < most_top)// payson1337 - github.com/paysonism
						most_top = bone.y;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (bone.y > most_bottom)// payson1337 - github.com/paysonism
						most_bottom = bone.y;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			auto actor_height = most_bottom - most_top;// payson1337 - github.com/paysonism
			auto actor_width = most_right - most_left;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto calculated_distance = max_distance - distance;// payson1337 - github.com/paysonism
			auto offset = calculated_distance * 0.035;// payson1337 - github.com/paysonism
			auto corner_wide = actor_width / 3;// payson1337 - github.com/paysonism
			auto corner_heit = actor_height / 3;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto text_offset = double(0);// payson1337 - github.com/paysonism
			fvector2d bottom_middle;// payson1337 - github.com/paysonism
			if (!settings::style::performance) {// payson1337 - github.com/paysonism
				bottom_middle = fvector2d(most_left + actor_width / 2, fortnite::s_bottom_2.y);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			else {// payson1337 - github.com/paysonism
				bottom_middle = fvector2d(most_left + actor_width / 2, fortnite::s_bottom.y);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::cornered_box) {// payson1337 - github.com/paysonism
				//top left// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_top - offset), fvector2d(most_left - offset + corner_wide, most_top - offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_top - offset), fvector2d(most_left - offset, most_top - offset + corner_heit), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
								//top right// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_right + offset, most_top - offset), fvector2d(most_right + offset - corner_wide, most_top - offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_right + offset, most_top - offset), fvector2d(most_right + offset, most_top - offset + corner_heit), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
								//bottom left// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_bottom + offset), fvector2d(most_left - offset + corner_wide, most_bottom + offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_bottom + offset), fvector2d(most_left - offset, most_bottom + offset - corner_heit), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
								//bottom right// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_right + offset, most_bottom + offset), fvector2d(most_right + offset - corner_wide, most_bottom + offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_right + offset, most_bottom + offset), fvector2d(most_right + offset, most_bottom + offset - corner_heit), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
								// Outline on the other side// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
			if (settings::player::normal_box) {// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_top - offset), fvector2d(most_left - offset, most_bottom + offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					// right line// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_right + offset, most_top - offset), fvector2d(most_right + offset, most_bottom + offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
									// top line// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_top - offset), fvector2d(most_right + offset, most_top - offset), esp_color, 1.f);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
									// bottom line// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(most_left - offset, most_bottom + offset), fvector2d(most_right + offset, most_bottom + offset), esp_color, 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::player_name) {// payson1337 - github.com/paysonism
				if (player) {// payson1337 - github.com/paysonism
					auto playername = defines::lib->get_player_name_safe(player, defines::actor_player_nameprivate);// payson1337 - github.com/paysonism
					render::text(playername.c_str(), fvector2d(bottom_middle.x, bottom_middle.y + text_offset), flinearcolor(1.f, 1.f, 0.f, 1.f), true, false, settings::style::text_outlined);// payson1337 - github.com/paysonism
					text_offset += 15;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::display_distance) {// payson1337 - github.com/paysonism
				auto final = defines::string->build_string_double(L"", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
				render::text(final.c_str(), fvector2d(bottom_middle.x, bottom_middle.y + text_offset), flinearcolor(1.f, 1.f, 1.f, 1.f), true, false, settings::style::text_outlined);// payson1337 - github.com/paysonism
				text_offset += 15;// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::active_weapon) {// payson1337 - github.com/paysonism
				if (auto current_weapon = player->get_current_weapon()) {// payson1337 - github.com/paysonism
					if (auto weapon_data = current_weapon->get_weapon_data()) {// payson1337 - github.com/paysonism
						auto display_name = weapon_data->display_name();// payson1337 - github.com/paysonism
						if (display_name.data && display_name.c_str()) {// payson1337 - github.com/paysonism
							auto tier = weapon_data->get_tier();// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							auto render_color = flinearcolor();// payson1337 - github.com/paysonism
							if (tier == fort_item_tier::I) render_color = flinearcolor(0.4f, 0.4f, 0.4f, 1.f);// payson1337 - github.com/paysonism
							else if (tier == fort_item_tier::II) render_color = flinearcolor(0.2f, 0.8f, 0.4f, 1.f);// payson1337 - github.com/paysonism
							else if (tier == fort_item_tier::III) render_color = flinearcolor(0.f, 0.4f, 0.8f, 1.f);// payson1337 - github.com/paysonism
							else if (tier == fort_item_tier::IV) render_color = flinearcolor(1.f, 0.f, 1.f, 1.f);// payson1337 - github.com/paysonism
							else if (tier == fort_item_tier::V) render_color = flinearcolor(0.7f, 0.7f, 0.f, 1.f);// payson1337 - github.com/paysonism
							else if (tier == fort_item_tier::VI) render_color = flinearcolor(1.f, 1.f, 0.f, 1.f);// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							if (render_color) {// payson1337 - github.com/paysonism
								auto a = defines::string->build_string_int(display_name.c_str(), L" [", current_weapon->get_magazine_ammo_count(), L"");// payson1337 - github.com/paysonism
								auto b = defines::string->build_string_int(L"", L"/", current_weapon->get_bullets_per_clip(), L"]");// payson1337 - github.com/paysonism
								auto c = defines::string->concat_str_str(a, b);// payson1337 - github.com/paysonism
								render::text(c.c_str(), fvector2d(bottom_middle.x, bottom_middle.y + text_offset), render_color, true, false, settings::style::text_outlined);// payson1337 - github.com/paysonism
								text_offset += 15;// payson1337 - github.com/paysonism
							}// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::snapline) {// payson1337 - github.com/paysonism
				render::line_with_outline(fvector2d(center.x, screen_size.y - 15), fvector2d(bottom_middle.x, bottom_middle.y + text_offset), esp_color, 1.f);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::player::eyes)// payson1337 - github.com/paysonism
			{// payson1337 - github.com/paysonism
				frotator _Angle = player->get_actor_rotation();// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				fvector test2, headpos;// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				headpos = fortnite::head;// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				angle_rotation(_Angle, &test2);// payson1337 - github.com/paysonism
				test2.x *= 50;// payson1337 - github.com/paysonism
				test2.y *= 50;// payson1337 - github.com/paysonism
				test2.z *= 50;// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				fvector end = headpos + test2;// payson1337 - github.com/paysonism
				fvector2d test1, test3;// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				if (controller->w2s(headpos, &test1))// payson1337 - github.com/paysonism
				{// payson1337 - github.com/paysonism
					if (controller->w2s(end, &test3))// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						render::line_with_outline(fvector2d(test1.x, test1.y), fvector2d(test3.x, test3.y), { 1.0f, 0.0f, 0.0f, 1.0f }, 1.f);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (!teammate && !local_pawn_holding_pickaxe && ((settings::aimbot::visible_only && visible) || (!settings::aimbot::visible_only)) && local_pawn && render::in_circle(center.x, center.y, radius, fortnite::s_head.x, fortnite::s_head.y)) {// payson1337 - github.com/paysonism
				double distance = defines::math->distance2d(fortnite::s_head, center);// payson1337 - github.com/paysonism
				if (distance < closest_distance) {// payson1337 - github.com/paysonism
					target_player = player;// payson1337 - github.com/paysonism
					closest_distance = distance;// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (settings::aimbot::enable) {// payson1337 - github.com/paysonism
			auto temp_silent_active = false;// payson1337 - github.com/paysonism
			auto temp_silent_rotation = frotator();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto temp_sticky_silent_active = false;// payson1337 - github.com/paysonism
			auto temp_sticky_silent_rotation = frotator();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (settings::aimbot::show_fov) {// payson1337 - github.com/paysonism
				render::circle(center, radius, 100, flinearcolor(1.f, 0.f, 1.f, 1.f));// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (target_player && local_pawn) {// payson1337 - github.com/paysonism
				if (auto mesh = target_player->get_pawn_mesh()) {// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					int32_t bone = 68;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::bones::head)// payson1337 - github.com/paysonism
						bone = 68;// payson1337 - github.com/paysonism
					else if (settings::bones::neck)// payson1337 - github.com/paysonism
						bone = 67;// payson1337 - github.com/paysonism
					else if (settings::bones::torso)// payson1337 - github.com/paysonism
						bone = 7;// payson1337 - github.com/paysonism
					else if (settings::bones::pelvis)// payson1337 - github.com/paysonism
						bone = 2;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					auto aim_location = mesh->get_bone_location(bone);// payson1337 - github.com/paysonism
					auto esp_color = flinearcolor(1.f, 1.f, 1.f, 1.f);// payson1337 - github.com/paysonism
					auto visible = target_player->was_recently_rendered(0.f);// payson1337 - github.com/paysonism
					if (visible) {// payson1337 - github.com/paysonism
						esp_color = flinearcolor(0.5f, 1.f, 0.5f, 1.f);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else {// payson1337 - github.com/paysonism
						esp_color = flinearcolor(1.0f, 0.5f, 0.5f, 1.f);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					if (settings::aimbot::target_line) {// payson1337 - github.com/paysonism
						auto aim_screen = fvector2d();// payson1337 - github.com/paysonism
						if (controller->w2s(aim_location, &aim_screen) && aim_screen) {// payson1337 - github.com/paysonism
							render::line_with_outline(center, aim_screen, esp_color, 1.f);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					if (settings::aimbot::bulletp)// payson1337 - github.com/paysonism
					{// payson1337 - github.com/paysonism
						tarray<uobject*> projectile_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_projectile_class);// payson1337 - github.com/paysonism
						for (int i = 0; i < projectile_array.size(); i++) {// payson1337 - github.com/paysonism
							if (!projectile_array.valid(i)) continue;// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							auto projectile = (actor*)projectile_array[i];// payson1337 - github.com/paysonism
							if (!projectile) continue;// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							auto object_name = defines::system->get_object_name(projectile);// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							if (!defines::string->contains(object_name.c_str(), L"Bullet", false, false))// payson1337 - github.com/paysonism
								continue;// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							projectile->set_actor_location(aim_location, false, 0, false);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					if (controller->is_key_down(defines::right_mouse_button)) {// payson1337 - github.com/paysonism
						if (settings::aimbot::silent) {// payson1337 - github.com/paysonism
							player_silent = true;// payson1337 - github.com/paysonism
							temp_silent_active = true;// payson1337 - github.com/paysonism
							temp_silent_rotation = defines::math->find_look_at_rotation(camera_location, aim_location);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
						else if (settings::aimbot::sticky_silent) {// payson1337 - github.com/paysonism
							temp_sticky_silent_active = true;// payson1337 - github.com/paysonism
							temp_sticky_silent_rotation = defines::math->find_look_at_rotation(camera_location, aim_location);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
						else if (settings::aimbot::memory) {// payson1337 - github.com/paysonism
							fortnite::set_aim(world, controller, camera_location, camera_rotation, aim_location, settings::aimbot::interpolate, settings::aimbot::constant, settings::aimbot::interpolate_speed);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
						else if (settings::aimbot::mouse) {// payson1337 - github.com/paysonism
							float width = ((double)canvas->clip_x());// payson1337 - github.com/paysonism
							float height = ((double)canvas->clip_y());// payson1337 - github.com/paysonism
							// payson1337 - github.com/paysonism
							fortnite::set_aim_mouse(controller, aim_location, width, height, settings::aimbot::mouse_speed);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			fortnite::temp::silent_active = temp_silent_active;// payson1337 - github.com/paysonism
			fortnite::temp::silent_rotation = temp_silent_rotation;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			fortnite::temp::sticky_silent_active = temp_sticky_silent_active;// payson1337 - github.com/paysonism
			fortnite::temp::sticky_silent_rotation = temp_sticky_silent_rotation;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscactors::vehicles)// payson1337 - github.com/paysonism
	{// payson1337 - github.com/paysonism
		tarray<uobject*> vehicle_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_vehicle_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < vehicle_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!vehicle_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto vehicle = (vehicle_actor*)vehicle_array[i];// payson1337 - github.com/paysonism
			if (!vehicle) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = vehicle->get_actor_location();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::miscactors::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (controller->w2s(world_location, &screen_location)) {// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				if (settings::miscactors::display_distance) {// payson1337 - github.com/paysonism
					auto final = defines::string->build_string_double(vehicle->get_display_name().c_str(), L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
					render::text(final.c_str(), screen_location, flinearcolor(1.f, 0.f, 1.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else {// payson1337 - github.com/paysonism
					render::text(vehicle->get_display_name().c_str(), screen_location, flinearcolor(1.f, 0.f, 1.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscactors::flags)// payson1337 - github.com/paysonism
	{// payson1337 - github.com/paysonism
		tarray<uobject*> flag_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_flag_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < flag_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!flag_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto flag = (flag_actor*)flag_array[i];// payson1337 - github.com/paysonism
			if (!flag) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = flag->get_actor_location();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::miscactors::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (controller->w2s(world_location, &screen_location)) {// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				if (settings::miscactors::display_distance) {// payson1337 - github.com/paysonism
					auto final = defines::string->build_string_double(L"Flag", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
					render::text(final.c_str(), screen_location, flinearcolor(0.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else {// payson1337 - github.com/paysonism
					render::text(L"Flag", screen_location, flinearcolor(0.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscactors::traps)// payson1337 - github.com/paysonism
	{// payson1337 - github.com/paysonism
		tarray<uobject*> trap_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_trap_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < trap_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!trap_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto trap = (trap_actor*)trap_array[i];// payson1337 - github.com/paysonism
			if (!trap) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = trap->get_actor_location();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::miscactors::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (controller->w2s(world_location, &screen_location)) {// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				if (settings::miscactors::display_distance) {// payson1337 - github.com/paysonism
					auto final = defines::string->build_string_double(L"Trap", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
					render::text(final.c_str(), screen_location, flinearcolor(0.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else {// payson1337 - github.com/paysonism
					render::text(L"Trap", screen_location, flinearcolor(0.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::miscactors::rifts) {// payson1337 - github.com/paysonism
		tarray<uobject*> rift_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_rift_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < rift_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!rift_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto rift = (rift_actor*)rift_array[i];// payson1337 - github.com/paysonism
			if (!rift) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = rift->get_actor_location();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::miscactors::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (controller->w2s(world_location, &screen_location)) {// payson1337 - github.com/paysonism
				if (settings::miscactors::display_distance) {// payson1337 - github.com/paysonism
					auto final = defines::string->build_string_double(L"Rift", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
					render::text(final.c_str(), screen_location, flinearcolor(1.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else {// payson1337 - github.com/paysonism
					render::text(L"Rift", screen_location, flinearcolor(1.f, 1.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::weakspot::enable) {// payson1337 - github.com/paysonism
		weakspot_actor* target_weakspot = 0;// payson1337 - github.com/paysonism
		tarray<uobject*> weakspot_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_weakspot_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < weakspot_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!weakspot_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto weakspot = (weakspot_actor*)weakspot_array[i];// payson1337 - github.com/paysonism
			if (!weakspot) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (!weakspot->is_active()) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			target_weakspot = weakspot;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		auto temp_silent_active = false;// payson1337 - github.com/paysonism
		auto temp_silent_rotation = frotator();// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (target_weakspot) {// payson1337 - github.com/paysonism
			auto aim_location = target_weakspot->get_actor_location();// payson1337 - github.com/paysonism
			auto aim_screen = fvector2d();// payson1337 - github.com/paysonism
			if (controller->w2s(aim_location, &aim_screen) && aim_screen) {// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				render::text(L"[X]", aim_screen, flinearcolor(1.f, 0.f, 0.f, 1.f), true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				// payson1337 - github.com/paysonism
				if (settings::weakspot::weakspot_aimbot && local_pawn) {// payson1337 - github.com/paysonism
					if (settings::weakspot::target_line) {// payson1337 - github.com/paysonism
						render::line_with_outline(center, aim_screen, flinearcolor(1.f, 0.f, 0.f, 1.f), 1.f);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					if (controller->is_key_down(defines::left_mouse_button)) {// payson1337 - github.com/paysonism
						if (settings::weakspot::silent) {// payson1337 - github.com/paysonism
							temp_silent_active = true;// payson1337 - github.com/paysonism
							temp_silent_rotation = defines::math->find_look_at_rotation(camera_location, aim_location);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
						else {// payson1337 - github.com/paysonism
							fortnite::set_aim(world, controller, camera_location, camera_rotation, aim_location, settings::weakspot::interpolate, settings::weakspot::constant, settings::weakspot::interpolate_speed);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
		if (!player_silent) {// payson1337 - github.com/paysonism
			fortnite::temp::silent_active = temp_silent_active;// payson1337 - github.com/paysonism
			fortnite::temp::silent_rotation = temp_silent_rotation;// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::pickups::enable) {// payson1337 - github.com/paysonism
		tarray<uobject*> pickup_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_pickup_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < pickup_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!pickup_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto pickup = (pickup_actor*)pickup_array[i];// payson1337 - github.com/paysonism
			if (!pickup) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = pickup->get_actor_location();// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::pickups::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (auto definition = pickup->get_item_definition()) {// payson1337 - github.com/paysonism
				auto display_name = definition->display_name();// payson1337 - github.com/paysonism
				if (display_name.data && display_name.c_str()) {// payson1337 - github.com/paysonism
					auto render_color = flinearcolor();// payson1337 - github.com/paysonism
					auto tier = definition->get_tier();// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::pickups::common && tier == fort_item_tier::I) render_color = flinearcolor(0.4f, 0.4f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					else if (settings::pickups::uncommon && tier == fort_item_tier::II) render_color = flinearcolor(0.2f, 0.8f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					else if (settings::pickups::rare && tier == fort_item_tier::III) render_color = flinearcolor(0.f, 0.4f, 0.8f, 1.f);// payson1337 - github.com/paysonism
					else if (settings::pickups::epic && tier == fort_item_tier::IV) render_color = flinearcolor(1.f, 0.f, 1.f, 1.f);// payson1337 - github.com/paysonism
					else if (settings::pickups::legendary && tier == fort_item_tier::V) render_color = flinearcolor(0.7f, 0.7f, 0.f, 1.f);// payson1337 - github.com/paysonism
					else if (settings::pickups::mythic && tier == fort_item_tier::VI) render_color = flinearcolor(1.f, 1.f, 0.f, 1.f);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					if (settings::radar::enable && settings::radar::pickups && render_color) {// payson1337 - github.com/paysonism
						fortnite::radar::add_to_radar(world_location, render_color);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
					if (controller->w2s(world_location, &screen_location) && screen_location) {// payson1337 - github.com/paysonism
						if (render_color) {// payson1337 - github.com/paysonism
							if (settings::pickups::lines && !render::in_circle(center.x, center.y, settings::pickups::line_offset, screen_location.x, screen_location.y)) {// payson1337 - github.com/paysonism
								double angle = defines::math->atan2(screen_location.y - center.y, screen_location.x - center.x);// payson1337 - github.com/paysonism
								// payson1337 - github.com/paysonism
								double x = settings::pickups::line_offset * defines::math->cos(angle) + center.x;// payson1337 - github.com/paysonism
								double y = settings::pickups::line_offset * defines::math->sin(angle) + center.y;// payson1337 - github.com/paysonism
								// payson1337 - github.com/paysonism
								fvector2d end_pos = fvector2d(x, y);// payson1337 - github.com/paysonism
								render::line_with_outline(end_pos, fvector2d(screen_location.x, screen_location.y + 8), render_color, 1.f);// payson1337 - github.com/paysonism
							}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
							if (settings::pickups::display_distance) {// payson1337 - github.com/paysonism
								auto final = defines::string->build_string_double(display_name.c_str(), L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
								render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
							}// payson1337 - github.com/paysonism
							else render::text(display_name.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
						}// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	if (settings::containers::enable) {// payson1337 - github.com/paysonism
		tarray<uobject*> container_array = defines::game_statics->get_all_actors_of_class(world, defines::actor_container_class);// payson1337 - github.com/paysonism
		for (int i = 0; i < container_array.size(); i++) {// payson1337 - github.com/paysonism
			if (!container_array.valid(i)) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto container = (container_actor*)container_array[i];// payson1337 - github.com/paysonism
			if (!container) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (settings::containers::ignore_opened && container->already_searched()) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto object_name = defines::system->get_object_name(container);// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto screen_location = fvector2d();// payson1337 - github.com/paysonism
			auto world_location = container->get_actor_location();// payson1337 - github.com/paysonism
			auto distance = defines::math->vector_distance(camera_location, world_location) * 0.01;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			if (distance > settings::containers::max_distance) continue;// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto render_color = flinearcolor(1.f, 1.f, 1.f, 1.f);// payson1337 - github.com/paysonism
			if (controller->w2s(world_location, &screen_location) && screen_location) {// payson1337 - github.com/paysonism
				if (settings::containers::chest && defines::string->contains(object_name.c_str(), L"Tiered_Chest", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(1.f, 1.f, 0.f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Chest ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Chest", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::ammo_box && defines::string->contains(object_name.c_str(), L"Tiered_Ammo", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(0.4f, 0.4f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Ammo box ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Ammo box", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::chest && defines::string->contains(object_name.c_str(), L"AlwaysSpawn_NormalChest", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(1.f, 1.f, 0.f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Basic chest ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Basic chest", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::cooler_and_food && defines::string->contains(object_name.c_str(), L"Cooler_Container", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(0.f, 1.f, 1.f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Cooler ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Cooler", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::cooler_and_food && defines::string->contains(object_name.c_str(), L"FoodBox_Produce", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(0.f, 1.f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Food box ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Food box", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::safe && defines::string->contains(object_name.c_str(), L"Tiered_Safe", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(1.f, 0.f, 0.f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Safe ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Safe", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::others && defines::string->contains(object_name.c_str(), L"Barrel_FishingRod", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(0.4f, 0.4f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Fishing rod ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Fishing rod", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::others && defines::string->contains(object_name.c_str(), L"CashRegister", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(0.4f, 0.4f, 0.4f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Cash register ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Cash register", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				else if (settings::containers::chest && defines::string->contains(object_name.c_str(), L"BuriedChest", false, false)) {// payson1337 - github.com/paysonism
					render_color = flinearcolor(1.f, 1.f, 0.f, 1.f);// payson1337 - github.com/paysonism
					if (settings::containers::display_distance) {// payson1337 - github.com/paysonism
						auto final = defines::string->build_string_double(L"Buried chest ", L"[", defines::math->round(distance), L"m]");// payson1337 - github.com/paysonism
						render::text(final.c_str(), screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
					}// payson1337 - github.com/paysonism
					else render::text(L"Buried chest", screen_location, render_color, true, true, settings::style::text_outlined);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
				if (settings::containers::lines && render_color && !render::in_circle(center.x, center.y, settings::containers::line_offset, screen_location.x, screen_location.y)) {// payson1337 - github.com/paysonism
					double angle = defines::math->atan2(screen_location.y - center.y, screen_location.x - center.x);// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					double x = settings::containers::line_offset * defines::math->cos(angle) + center.x;// payson1337 - github.com/paysonism
					double y = settings::containers::line_offset * defines::math->sin(angle) + center.y;// payson1337 - github.com/paysonism
					// payson1337 - github.com/paysonism
					fvector2d end_pos = fvector2d(x, y);// payson1337 - github.com/paysonism
					render::line_with_outline(end_pos, fvector2d(screen_location.x, screen_location.y + 8), render_color, 1.f);// payson1337 - github.com/paysonism
				}// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
			if (settings::radar::enable && settings::radar::containers && render_color) {// payson1337 - github.com/paysonism
				fortnite::radar::add_to_radar(world_location, render_color);// payson1337 - github.com/paysonism
			}// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
namespace payson1337 {// payson1337 - github.com/paysonism
	using draw_transition_sim = void(*)(ugameviewportclient* viewport, ucanvas* canvas);// payson1337 - github.com/paysonism
	draw_transition_sim draw_transition_o = 0;// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	// payson1337 - github.com/paysonism
	void draw_transition(ugameviewportclient* viewport, ucanvas* canvas) {// payson1337 - github.com/paysonism
		subzero_load(viewport, canvas);// payson1337 - github.com/paysonism
		return draw_transition_o(viewport, canvas);// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	static void init() {// payson1337 - github.com/paysonism
		game = get_module(L"FortniteClient-Win64-Shipping.exe");// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (!game)// payson1337 - github.com/paysonism
			return;// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		defines::init();// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		// payson1337 - github.com/paysonism
		if (auto world = uobject::find_object(L"Frontend", reinterpret_cast<uobject*>(-1))) {// payson1337 - github.com/paysonism
			auto game_instance = defines::game_statics->get_game_instance(world);// payson1337 - github.com/paysonism
			auto local_player = game_instance->get_local_players()[0];// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto controller = defines::game_statics->get_player_controller(world, std::int32_t(0));// payson1337 - github.com/paysonism
			auto viewport = local_player->get_viewport();// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			auto engine = (uengine*)defines::system->get_outer_object(game_instance);// payson1337 - github.com/paysonism
			render::font = engine->get_font(); // payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			// payson1337 - github.com/paysonism
			draw_transition_o = vmt<decltype(draw_transition_o)>(std::uintptr_t(viewport), std::uintptr_t(draw_transition), 0x70);// payson1337 - github.com/paysonism
		}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism
	}// payson1337 - github.com/paysonism
}// payson1337 - github.com/paysonism
// payson1337 - github.com/paysonism