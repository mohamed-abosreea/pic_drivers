/* 
 * File:   std_lib.h
 * Author: Mohamed Abosreea
 *
 * Created on March 25, 2023, 2:05 PM
 */

#ifndef STD_LIB_H
#define	STD_LIB_H

#define SET_BIT(REG  , BIT)     (REG |= (1<<BIT))
#define CLEAR_BIT(REG  , BIT)   (REG &= ~(1<<BIT))
#define TOGGLE_BIT(REG  , BIT)  (REG ^= (1<<BIT))
#define GET_BIT(REG  , BIT)     ((REG >> BIT) & 1)
#endif	/* STD_LIB_H */

