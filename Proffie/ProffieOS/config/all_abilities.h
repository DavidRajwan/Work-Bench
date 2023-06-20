#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 1
#define NUM_BUTTONS 1
#define VOLUME 1000
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 2.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_ALL_EDIT_OPTIONS
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define COLOR_CHANGE_DIRECT
#define FETT263_EDIT_MODE_MENU
#define DISABLE_BASIC_PARSER_STYLES
#define FETT263_SAVE_CHOREOGRAPHY
#define FETT263_DUAL_MODE_SOUND
#define FETT263_MAX_CLASH 16
#define FETT263_MULTI_PHASE
#define FETT263_SAY_COLOR_LIST
#define FETT263_SAY_COLOR_LIST_CC
#define FETT263_SAY_BATTERY_PERCENT
#define FETT263_MOTION_WAKE_POWER_BUTTON
#define FETT263_QUOTE_PLAYER_START_ON
#define FETT263_SWING_ON
#define FETT263_TWIST_OFF
#define FETT263_TWIST_ON_PREON
#define FETT263_SAVE_GESTURE_OFF
#define FETT263_FORCE_PUSH
#define NO_REPEAT_RANDOM
#define DISABLE_DIAGNOSTIC_COMMANDS
#endif 

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif


#ifdef CONFIG_PRESETS
Preset presets[] = {
   { "RgueCmdr;common", "tracks/venus.wav",
    /* copyright Fett263 CustomBlade (Primary Blade) OS6 Style
    https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
    OS6.7 v4.021
    Single Style
    Dual Phase (Force Change)
    Default: Hyper Responsive Rotoscope (Original Trilogy)
    1: Fallen Order Second Sister

    Base Color: Rgb<255,0,0> (0)
    Dual Phase Control: use Force to toggle phases.

    --Effects Included--
    Preon Effect: Overload (PreOn Color)
    Ignition Effect: SparkTip Ignition
    Retraction Effect: Glitch Off
    CoolDown Effect: Power Burst Reverse
    PostOff Effect: Emitter Spark (Emitter Size)
    Lockup Effect: Original Localized Lockup, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
    LightningBlock Effect: Responsive Lightning Block
    Drag Effect: Intensity Fire Drag
    Melt Effect: Intensity Melt
    Stab Effect: Sparking Stab
    Blast Effect: Blast Wave (Random)
    Clash Effect: Real Clash V3
    Emitter Effect: Unstable Flare
    Emitter Off Effect: Base Color Glow (One-Time Preset Indicator)
    Battery Level: Full Blade (Green to Red)
    */
    StylePtr<Layers<ColorSelect<IncrementModuloF<EffectPulseF<EFFECT_FORCE>,Int<32000>>,TrColorCycle<2000>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<2570>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>,AlphaL<RandomPerLEDFlickerL<RgbArg<EMITTER_COLOR_ARG,Rgb<255,255,255>>>,SmoothStep<Scale<NoisySoundLevel,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<6000>>>,Int<-6000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RandomPerLEDFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<180,130,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,AlphaL<TransitionEffectL<TrSelect<Scale<ClashImpactF<>,Int<0>,Int<4>>,TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-10000>>>,Scale<ClashImpactF<>,Int<8000>,Int<12000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<600>>>>,TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-10000>>>>,TrSparkX<Remap<CenterDistF<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-10000>>>>,Stripes<1500,-3000,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-10000>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,TrConcat<TrInstant,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,TrFadeX<Scale<ClashImpactF<>,Int<300>,Int<500>>>>>,EFFECT_CLASH>,Scale<ClashImpactF<>,Int<24000>,Int<32768>>>,LockupTrL<AlphaMixL<Bump<Sin<Int<12>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-8000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<8000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<Stripes<2000,4000,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Mix<Sin<Int<50>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<4096>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,255,255>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<0>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,ColorSelect<IncrementWithReset<EffectPulseF<EFFECT_IGNITION>,EffectPulseF<EFFECT_NEWFONT>,Int<1>>,TrInstant,Mix<SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-1000>>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,Black>>,TransitionEffectL<TrConcat<TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,10>,SmoothStep<IntArg<PREON_SIZE_ARG,16000>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,15>,SmoothStep<Sum<Int<2000>,IntArg<PREON_SIZE_ARG,16000>>,Int<-4000>>>,TrFadeX<Mult<Int<8192>,WavLen<EFFECT_PREON>>>,AlphaL<HumpFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,20>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,16000>>,Int<-4000>>>,TrBoingX<Mult<Int<8192>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Rgb<255,255,255>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,Mix<BatteryLevel,Red,Green>,TrFade<300>>,EFFECT_BATTERY_LEVEL>>>()}


   { "SmthFuzz;common", "tracks/uranus.wav",
    /* copyright Fett263 CustomBlade (Primary Blade) OS6 Style
    https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
    OS6.7 v4.021
    Single Style
    Interactive Clash Instability
    Default: Fallen Order Second Sister
    1: Fallen Order Second Sister

    Base Color: Rgb<255,0,0> (0)
    Each Clash or Lockup with apply Style 2 (Instability) in increasing levels based on strength of the clash, allowing time to pass between clashes allows the blade to re-stabilize. (approx 5 seconds)

    --Effects Included--
    Preon Effect: Faulty Ignition (PreOn Color)
    Ignition Effect: Cycle Up
    PowerUp Effect: Rey TROS Spark
    Retraction Effect: Multi-Point In
    CoolDown Effect: Power Burst Reverse
    PostOff Effect: Emitter Glow (Preon Size)
    Lockup Effect: Responsive Lockup, Begin Effect: Full Blade Flash, End Effect: Full Blade Absorb
    LightningBlock Effect: Responsive Lightning Block
    Drag Effect: Fire Drag
    Melt Effect: Responsive Melt
    Stab Effect: AudioFlicker Stab
    Blast Effect: Blast Wave (Random)
    Clash Effect: Random Clash
    Swing Effect: Force Boost Pixelate Swing (Scaled Full Blade)
    Battery Level: Full Blade (Green to Red)
    */
    StylePtr<Layers<Mix<HoldPeakF<IncrementWithReset<Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,ThresholdPulseF<IncrementWithReset<ThresholdPulseF<BlinkingF<Int<1000>,Int<500>>,Int<32000>>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<32768>,Int<8000>>,Int<32000>>,Int<32768>,Scale<ClashImpactF<>,Int<2000>,Int<8000>>>,Int<2000>,Int<10000>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<395>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Scale<Sin<Int<20>>,Int<395>,Int<0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<10280>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<395>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Scale<Sin<Int<20>>,Int<395>,Int<0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<395>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Scale<Sin<Int<20>>,Int<395>,Int<0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,Mix<Int<2570>,Black,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<395>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Scale<Sin<Int<20>>,Int<395>,Int<0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,Gradient<RotateColorsX<Scale<Sin<Int<20>>,Int<0>,Int<395>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,RotateColorsX<Scale<Sin<Int<20>>,Int<395>,Int<0>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>>,StripesX<Int<1500>,Scale<SlowNoise<Int<2500>>,Int<-3000>,Int<-5000>>,RgbArg<ALT_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<10280>,Black,RgbArg<ALT_COLOR_ARG,Rgb<118,0,194>>>,RgbArg<ALT_COLOR_ARG,Rgb<118,0,194>>,Mix<Int<2570>,Black,RgbArg<ALT_COLOR_ARG,Rgb<118,0,194>>>,RgbArg<ALT_COLOR_ARG,Rgb<118,0,194>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelay<30000>,TrFade<300>>,AlphaL<RandomBlink<10000,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,Black>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TrFade<300>>,EFFECT_FORCE>,TransitionEffectL<TrConcat<TrJoin<TrDelay<200>,TrInstant>,AlphaL<Green,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<300>,AlphaL<Blue,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-500>>>,TrFade<500>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<115,15,240>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<115,15,240>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<180,130,0>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<EffectPosition<EFFECT_CLASH>,Scale<ClashImpactF<>,Int<9000>,Int<12000>>>,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<16384>,Black,RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16390>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,Rgb<255,0,0>>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<255,0,0>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrWipeIn<200>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrColorCycleX<IgnitionTime<300>>,TrConcat<TrInstant,AlphaL<Black,LayerFunctions<LinearSectionF<Int<6144>,Scale<Trigger<EFFECT_RETRACTION,RetractionTime<0>,RetractionTime<0>,Int<0>>,Int<0>,Int<12288>>>,LinearSectionF<Int<16384>,Scale<Trigger<EFFECT_RETRACTION,RetractionTime<0>,RetractionTime<0>,Int<0>>,Int<0>,Int<12288>>>,LinearSectionF<Int<26624>,Scale<Trigger<EFFECT_RETRACTION,RetractionTime<0>,RetractionTime<0>,Int<0>>,Int<0>,Int<12288>>>>>,TrDelayX<RetractionTime<0>>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Mult<Int<16384>,WavLen<EFFECT_PREON>>,Mult<Int<10922>,WavLen<EFFECT_PREON>>,Mult<Int<5462>,WavLen<EFFECT_PREON>>>,BrownNoiseFlicker<Black,RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,100>,RandomPerLEDFlicker<RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,Rgb<50,50,50>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>,RotateColorsX<Int<4000>,RgbArg<PREON_COLOR_ARG,Rgb<100,100,150>>>>,White,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>,TrDelayX<WavLen<EFFECT_PREON>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<115,15,240>>,SmoothStep<IntArg<PREON_SIZE_ARG,16000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,Mix<BatteryLevel,Red,Green>,TrFade<300>>,EFFECT_BATTERY_LEVEL>>>()},


   { "SmthGrey;common", "tracks/mercury.wav",
    /* copyright Fett263 CustomBlade (Primary Blade) OS6 Style
    https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
    OS6.7 v4.021
    Single Style
    Interactive Idle Blade Corruption
    Default: Hyper Responsive Rotoscope (Original Trilogy)
    1: Ghostbusters Particle Beam (Original)

    Base Color: Rgb<255,0,0> (0)
    Whenever your blade is idle it will be overtaken by Style 2, swinging the blade will rid it of the corruption.

    --Effects Included--
    Preon Effect: Erratic (PreOn Color)
    Ignition Effect: Glitch On
    Retraction Effect: Glitch Off
    CoolDown Effect: Power Burst Reverse
    PostOff Effect: Emitter Glow (Preon Size)
    Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
    LightningBlock Effect: Original Lightning Block
    Drag Effect: Intensity Sparking Drag
    Melt Effect: Responsive Melt
    Stab Effect: Normal Stab
    Blast Effect: Blast Wave (Random)
    Clash Effect: Responsive Clash
    Swing Effect: Flame Thrower Swing
    Battery Level: Blade Location (Green to Red)
    */
    StylePtr<Layers<Mix<SmoothStep<Scale<IncrementWithReset<Scale<IsLessThan<SwingSpeed<400>,Int<24000>>,ThresholdPulseF<Int<0>,Int<1>>,ThresholdPulseF<Ifon<BlinkingF<Int<200>,Int<500>>,Int<0>>,Int<32000>>>,ThresholdPulseF<SwingSpeed<400>,Int<18000>>,Int<33000>,Int<500>>,Int<-2000>,Int<35000>>,Int<-2000>>,Mix<HoldPeakF<SwingSpeed<250>,Scale<SwingAcceleration<100>,Int<50>,Int<500>>,Scale<SwingAcceleration<>,Int<20000>,Int<10000>>>,RandomFlicker<StripesX<Int<15000>,Scale<HoldPeakF<SwingSpeed<200>,Scale<SwingAcceleration<100>,Int<50>,Int<300>>,Scale<SwingAcceleration<100>,Int<24000>,Int<16000>>>,Int<-3200>,Int<-200>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<19276>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,StaticFire<Mix<SmoothStep<Int<2000>,Int<-2000>>,Stripes<16000,-3900,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>,Mix<Int<8172>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>>,Mix<Int<16384>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>>,Stripes<2500,-3500,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>,Blue,Mix<Int<16000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,68,0>>>,DodgerBlue>>,White>,Blue,0,6,1,2000,3>>,AlphaL<StaticFire<Stripes<12000,-2000,RgbArg<SWING_COLOR_ARG,Rgb<0,255,255>>,RotateColorsX<Int<200>,RgbArg<SWING_COLOR_ARG,Rgb<0,255,255>>>>,Mix<Int<16384>,Black,RgbArg<SWING_COLOR_ARG,Rgb<0,255,255>>>,0,3,2,2000,8>,SmoothStep<Scale<HoldPeakF<Ifon<Scale<IsGreaterThan<SwingSpeed<500>,Int<16000>>,Int<2000>,SwingSpeed<300>>,Int<0>>,Scale<SwingAcceleration<>,Int<100>,Int<600>>,Scale<SwingAcceleration<>,Int<10000>,Int<4000>>>,Int<1000>,Int<40000>>,Int<-4000>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<5000,2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<0,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<0,255,255>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,255,255>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<255,255,255>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,0>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,255,0>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<300>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,TrConcat<TrJoin<TrDelayX<Mult<RetractionTime<0>,Int<16384>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<0,255,255>>>,TrWipeInX<Mult<RetractionTime<0>,Int<16384>>>>,Black>,TransitionEffectL<TrConcat<TrBoingX<Mult<Int<10922>,WavLen<EFFECT_PREON>>,5>,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<0,255,255>>,Int<100>>,SmoothStep<IntArg<PREON_SIZE_ARG,16000>,Int<-4000>>>,TrBoingX<Mult<Int<10922>,WavLen<EFFECT_PREON>>,3>,Black,TrBoingX<Mult<Int<7260>,WavLen<EFFECT_PREON>>,3>,AlphaL<BrownNoiseFlickerL<RgbArg<PREON_COLOR_ARG,Rgb<0,255,255>>,Int<200>>,SmoothStep<Sum<Int<4000>,IntArg<PREON_SIZE_ARG,16000>>,Int<-4000>>>,TrBoingX<Mult<Int<3664>,WavLen<EFFECT_PREON>>,3>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Int<0>>,TrJoin<TrDelay<1000>,TrInstant>,AlphaL<RgbArg<POSTOFF_COLOR_ARG,Rgb<0,255,255>>,SmoothStep<IntArg<PREON_SIZE_ARG,16000>,Int<-2000>>>,TrSmoothFadeX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<300>>,EFFECT_BATTERY_LEVEL>>>()},


   { "SmthJedi;common", "tracks/mars.wav",
   

   { "TeensySF;common", "tracks/mars.wav",
  

   { "TthCrstl;common", "tracks/mars.wav",
   

   { "RgueCmdr;common", "tracks/venus.wav",
   
   { "SmthGrey;common", "tracks/mercury.wav",
    &style_pov, "POV"},
    
   { "SmthJedi;common", "tracks/mars.wav",
    &style_charging, "Battery\nLevel"},

};
BladeConfig blades[] = {
 { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif
