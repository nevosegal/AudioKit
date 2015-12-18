#include "plumber.h"

int sporth_rms(sporth_stack *stack, void *ud)
{
    plumber_data *pd = ud;
    SPFLOAT in;
    SPFLOAT out;
    sp_rms *rms;

    switch(pd->mode) {
        case PLUMBER_CREATE:

#ifdef DEBUG_MODE
            fprintf(stderr, "rms: Creating\n");
#endif

            sp_rms_create(&rms);
            plumber_add_ugen(pd, SPORTH_RMS, rms);
            break;
        case PLUMBER_INIT:

#ifdef DEBUG_MODE
            fprintf(stderr, "rms: Initialising\n");
#endif

            if(sporth_check_args(stack, "f") != SPORTH_OK) {
                fprintf(stderr,"Not enough arguments for rms\n");
                stack->error++;
                return PLUMBER_NOTOK;
            }
            in = sporth_stack_pop_float(stack);
            rms = pd->last->ud;
            sp_rms_init(pd->sp, rms);
            sporth_stack_push_float(stack, 0);
            break;
        case PLUMBER_COMPUTE:
            in = sporth_stack_pop_float(stack);
            rms = pd->last->ud;
            sp_rms_compute(pd->sp, rms, &in, &out);
            sporth_stack_push_float(stack, out);
            break;
        case PLUMBER_DESTROY:
            rms = pd->last->ud;
            sp_rms_destroy(&rms);
            break;
        default:
            fprintf(stderr, "rms: Uknown mode!\n");
            break;
    }
    return PLUMBER_OK;
}
