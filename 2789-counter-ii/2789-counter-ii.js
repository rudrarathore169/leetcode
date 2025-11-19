/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */


/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

 var createCounter = function(init){
    const initi =init;
    return{
        increment: function(){
            return ++init;
        },
        decrement: function(){
            return --init;
        },
        reset: function(){
            init = initi;
            return init;
        }
        
    }
 };