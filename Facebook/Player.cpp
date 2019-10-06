#include "Player.h"
#include "imageAndText.h"
#include "videoAndText.h"

void Player::Play(const Status* status) const
{
	const Video *vid = dynamic_cast<const Video*>(status);
	const videoAndText *vat = dynamic_cast<const videoAndText*>(status);

	if (vat != nullptr)
	{
		if (vat->isVideoExist())
		{
			setTextColor(BLUE);
			cout << "Playing video..  ";
		}
	}
	else if (vid != nullptr)
	{
		if (vid->isVideoExist())
		{
			setTextColor(BLUE);
			cout << "Playing video..  ";
		}
	}

	setTextColor(LIGHTGREY);
}