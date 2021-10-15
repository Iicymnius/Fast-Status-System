#find;

		self.statusPlusCommandDict={
			"HTH" : "/stat ht",
			"INT" : "/stat iq",
			"STR" : "/stat st",
			"DEX" : "/stat dx",
		}

#add below;

		if app.ENABLE_STATUS_UP_RENEWAL:
			self.faststatusPlusCommandDict={
				"HTH" : "/stat ht 10",
				"INT" : "/stat iq 10",
				"STR" : "/stat st 10",
				"DEX" : "/stat dx 10",
			}

#find again;

				statusPlusCommand=self.statusPlusCommandDict[statusKey]

#change;

			if app.ENABLE_STATUS_UP_RENEWAL and app.IsPressed(app.DIK_LCONTROL):
				statusPlusCommand=self.faststatusPlusCommandDict[statusKey]
			else:
				statusPlusCommand=self.statusPlusCommandDict[statusKey]

#find again;

				self.__ShowStatToolTip(self.STAT_DESCRIPTION[stat])

#change;

			if app.ENABLE_STATUS_UP_RENEWAL:
				self.__ShowStatToolTip(localeInfo.FAST_STATUS_UP)
			else:
				self.__ShowStatToolTip(self.STAT_DESCRIPTION[stat])