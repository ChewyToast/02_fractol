int	get_color(int i)
{
	int	color;

	if (i < 2)
		color = 0x07365A;
	else if (i < 5)
		color = 0x083A61;
	else if (i < 8)
		color = 0x09416C;
	else if (i < 15)
		color = 0x094573;
	else if (i < 30)
		color = 0x0A4A7B;
	else if (i < 50)
		color = 0x0A4F83;
	else if (i < 58)
		color = 0x0C5892;
	else if (i < 65)
		color = 0x0E66A9;
	else if (i < 73)
		color = 0x0E6AB1;
	else if (i < 82)
		color = 0x0F6FB8;
	else if (i < 91)
		color = 0x0F73C0;
	else if (i < 100)
		color = 0x1078C8;
	else if (i < 108)
		color = 0x1183DA;
	else if (i < 116)
		color = 0x128BE6;
	else
		color = 0x149AFF;
	return (color);
}