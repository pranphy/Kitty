/*************************************************/
/** Author        : @PrakashGautam               */
/** First Written : Dec 30, 2012                 */
/** Last Updated  : Oct 20, 2013                 */
/** fb.com/pranphy<>http://pranphy.wordpress.com */
/*************************************************/


#include "Base/ScoresAndDisplays.h"

Players::Players(char*name,int lives,int scores)
{
    int l=strlen(name);
    Name=new char[l];
    strcpy(Name,name);
    Lives=lives;
    Scores=scores;
}
