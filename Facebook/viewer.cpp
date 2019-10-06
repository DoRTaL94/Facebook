#include "Viewer.h"
#include "imageAndText.h"
#include "videoAndText.h"

void Viewer::show(const Status* status) const
{
	const Text *txt = dynamic_cast<const Text*>(status);
	const Image *img = dynamic_cast<const Image*>(status);
	const videoAndText* vat = dynamic_cast<const videoAndText*>(status);
	const imageAndText* iat = dynamic_cast<const imageAndText*>(status);

	if (iat != nullptr)
	{
		if (iat->isImgExist())
		{
			setTextColor(YELLOW);
			cout << "Showing image..  ";
		}

		if (iat->getText().size() > 0)
		{
			setTextColor(LIGHTGREY);
			cout << "\"" << iat->getText() << "\"";
		}
	}
	else if (vat != nullptr)
	{
		if (vat->getText().size() > 0)
		{
			setTextColor(LIGHTGREY);
			cout << "\"" << vat->getText() << "\"";
		}
	}
	else if (txt != nullptr)
	{
		if (txt->getText().size() > 0)
		{
			setTextColor(LIGHTGREY);
			cout << "\"" << txt->getText() << "\"";
		}
	}
	else if (img != nullptr)
	{
		if (img->isImgExist())
		{
			setTextColor(YELLOW);
			cout << "Showing image..  ";
		}
	}

	setTextColor(LIGHTGREY);
}