import Data.Time
import Data.Time.Format
import Data.Time.Calendar.OrdinalDate

getLocalDate :: IO Day
getLocalDate =
    getCurrentTime >>= \currentTime ->
    getCurrentTimeZone >>= \timeZone ->
    return $ localDay (utcToLocalTime timeZone currentTime)

mondayBefore :: Day -> Day
mondayBefore day =
    let wd = snd $ mondayStartWeek day
    in addDays (fromIntegral $ negate (wd - 1)) day

daysFrom :: Day -> [Day]
daysFrom start = iterate (addDays 1) start

groupWeeks :: [Day] -> [[Day]]
groupWeeks [] = []
groupWeeks xs = take 7 xs : groupWeeks (drop 7 xs)

groupMonths :: [[Day]] -> [[[Day]]]
groupMonths [] = []
groupMonths xs = take 4 xs : groupMonths (drop 4 xs)

main :: IO ()
main = getLocalDate >>= print
                        . (take 2)
                        . groupMonths
                        . groupWeeks
                        . daysFrom
                        . mondayBefore
