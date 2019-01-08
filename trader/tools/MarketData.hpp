// MarketData.hpp

#pragma once

#include <string>
#include <vector>

/**
 * A consolidated class for querying
 * the Tradier API for quotes and IEX API for stock data.
 */
namespace tools
{
	class MarketData
	{
	public:
		// @param symbols - (i.e. "APPL", "AAPL150117C00440000", etc.)
		// @return current market prices of equities in symbols in same order
		static std::vector<double> getPrices(const std::vector<std::string>& symbols);

		// @return if trading is open
		static bool isOpen();

		// TODO: https://iextrading.com/developer/docs/#relevant
		// https://github.com/alpacahq/pipeline-live/blob/master/pipeline_live/data/iex/fundamentals.py
		static double getRSI();

		// get a bunch of key stats in one IEX query
		// @param fields - i.e. "marketcap", "dividendYield", "peRatioHigh", "peRatioLow"
		static std::vector<double> getKeyStats(const std::string& symbol, const std::vector<std::string>& fields = {});

	private:
		// querying is very similar across other functions
		// @param url - entire URL (sometimes data.api.markets, others paper-api...)
		// @param symbols - comma delimited list of ticker symbols
		// @param otherHeaders - any other path parameters to add
		// @return whole response as string
		static std::string marketQueryAlpaca (	
			std::string url, 
			const std::vector<std::string>& symbols = std::vector<std::string>(),
			const std::vector<std::string>& otherParams = std::vector<std::string>()
		);

		// query the IEX open API
		// @param url after https://api.iextrading.com/1.0/
		static std::string marketQueryIEX(const std::string& endOfUrl);
	};
}