//find;

ACMD(do_stat)
{
	char arg1[256];
	one_argument(argument, arg1, sizeof(arg1));

	if (!*arg1)
		return;

//change;

ACMD(do_stat)
{
	char arg1[256];
#ifdef ENABLE_STATUS_UP_RENEWAL
	char arg2[256];
	two_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2));
#else
	one_argument(argument, arg1, sizeof(arg1));
#endif

	if (!*arg1)
		return;

#ifdef ENABLE_STATUS_UP_RENEWAL
	int iStatUp = 1;
	if (*arg2)
		iStatUp = atoi(arg2);
#endif

//find again;

	if (ch->GetPoint(POINT_STAT) <= 0)
		return;

//change;

#ifdef ENABLE_STATUS_UP_RENEWAL
	if (ch->GetPoint(POINT_STAT) < iStatUp)
		iStatUp = ch->GetPoint(POINT_STAT);
#else
	if (ch->GetPoint(POINT_STAT) <= 0)
		return;
#endif

//find again;

	if (ch->GetRealPoint(idx) >= MAX_STAT)
		return;

	ch->SetRealPoint(idx, ch->GetRealPoint(idx) + 1);
	ch->SetPoint(idx, ch->GetPoint(idx) + 1);

//change;

#ifdef ENABLE_STATUS_UP_RENEWAL
	if ((ch->GetRealPoint(idx) + iStatUp) > MAX_STAT)
		iStatUp = MAX_STAT - ch->GetRealPoint(idx);

	if (iStatUp < 1)
#else
	if (ch->GetRealPoint(idx) >= MAX_STAT)
#endif
		return;
#ifdef ENABLE_STATUS_UP_RENEWAL
	ch->SetRealPoint(idx, ch->GetRealPoint(idx) + iStatUp);
	ch->SetPoint(idx, ch->GetPoint(idx) + iStatUp);
#else
	ch->SetRealPoint(idx, ch->GetRealPoint(idx) + 1);
	ch->SetPoint(idx, ch->GetPoint(idx) + 1);
#endif

//find again;

	ch->PointChange(POINT_STAT, -1);

//change;

#ifdef ENABLE_STATUS_UP_RENEWAL
	ch->PointChange(POINT_STAT, -iStatUp);
#else
	ch->PointChange(POINT_STAT, -1);
#endif