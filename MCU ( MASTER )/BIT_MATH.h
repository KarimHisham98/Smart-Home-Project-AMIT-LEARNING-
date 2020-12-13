/*
 * BIT_MATH.h
 *
 * Created: 1/12/2020 10:08:05 PM
 *  Author: Karim
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)  (REG |= (1<<BIT))
#define CLEAR_BIT(REG,BIT)  (REG &=~ (1<<BIT))
#define Toggle_BIT(REG,BIT) (REG ^= (1<<BIT))
#define READ_BIT(PORT,PIN)   ( 1 &   (PORT>>PIN) )



#endif /* BIT_MATH_H_ */