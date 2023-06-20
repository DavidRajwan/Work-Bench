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
   { "IronMan;common", "tracks/ironmansong.wav",
   /* copyright Fett263 StaticElectricity (Primary Blade) OS6 Style
    https://fett263.com/fett263-proffieOS6-style-library.html#StaticElectricity
    OS6.7 v4.021
    Single Style
    Base Style: Interactive Static Electricity Blade

    Base Color: Rgb<255,0,0> (Gradient Bright Down = Gradient: 2991)

    Interactive Static Electricity Blade Interactive Control: Swing to build up static energy on blade, clash to dissipate.

    --Effects Included--
    Preon Effect: Seismic Charge (PreOn Color)
    Ignition Effect: Glitch On
    PowerUp Effect: Power Flash
    Retraction Effect: Cycle Down
    CoolDown Effect: Unstable Cool Down Reverse
    PostOff Effect: Emitter Spark (Emitter Size)
    Lockup Effect: Intensity Lockup V1, Begin Effect: Real Clash, End Effect: Dissipate
    LightningBlock Effect: Responsive Lightning Block
    Drag Effect: Intensity Sparking Drag
    Melt Effect: Intensity Melt
    Blast Effect: Blast Wave (Random)
    Clash Effect: Real Clash V1
    Swing Effect: Interactive Lightning (Force Toggle)
    Emitter Effect: Emitter Flare
    Battery Level: Full Blade (Green to Red)

    Swing Option 0- Interactive Lightning (Force Toggle) Interactive Control: Force to enable/disable, Swing to throw Lightning.
    */
    StylePtr<Layers<Black,ColorSelect<IncrementWithReset<ThresholdPulseF<SwingSpeed<400>,Int<18000>>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<1>>,TrSelect<IncrementWithReset<ThresholdPulseF<SwingSpeed<400>,Int<18000>>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<1>>,TrConcat<TrInstant,Mix<Int<16384>,Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,White>,TrSmoothFade<500>>,TrSmoothFade<600>>,AudioFlicker<Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<18000>,Black,Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,Layers<StripesX<Int<6000>,Scale<IncrementWithReset<ThresholdPulseF<SwingSpeed<400>,Int<18000>>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<32000>,Int<2000>>,Int<-100>,Int<-3000>>,Mix<Int<9000>,Black,Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Mix<Int<18000>,Black,Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>,AlphaL<RandomPerLEDFlickerL<Black>,IncrementWithReset<ThresholdPulseF<SwingSpeed<400>,Int<18000>>,Sum<EffectPulseF<EFFECT_CLASH>,EffectPulseF<EFFECT_LOCKUP_BEGIN>>,Int<30000>,Int<4000>>>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<180,130,0>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,2000>,Int<-6000>>>,ColorSelect<IncrementF<EffectPulseF<EFFECT_FORCE>,Int<32000>,Int<2>,Int<1>>,TrSmoothFade<500>,AlphaL<Gradient<Mix<Int<2991>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,White>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Int<0>>,AlphaL<BrownNoiseFlickerL<StripesX<Int<2600>,Scale<IncrementWithReset<ThresholdPulseF<StrobeF<Int<6>,Int<1>>,Int<32000>>,ThresholdPulseF<ThresholdPulseF<IsLessThan<HoldPeakF<Ifon<SwingSpeed<400>,Int<0>>,Int<150>,Int<32000>>,Int<8000>>,Int<32000>>>,Int<30000>,Int<3000>>,Int<-1200>,Int<-4000>>,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<16384>,Black,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<16384>,RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,White>>,Int<50>>,SmoothStep<IncrementWithReset<Scale<IsGreaterThan<HoldPeakF<Ifon<SwingSpeed<400>,Int<0>>,Int<150>,Int<32000>>,Int<18000>>,Int<0>,ThresholdPulseF<StrobeF<Scale<HoldPeakF<Ifon<SwingAcceleration<>,Int<0>>,Int<150>,Int<32000>>,Int<20>,Int<200>>,Int<1>>,Int<32000>>>,ThresholdPulseF<IsLessThan<HoldPeakF<Ifon<SwingSpeed<400>,Int<0>>,Int<150>,Int<32000>>,Int<8000>>,Int<32000>>,Int<42000>,Int<1500>>,Int<-8000>>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,TrFade<1000>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Stripes<3000,3500,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,RandomPerLEDFlicker<Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Black>,BrownNoiseFlicker<RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,200>,RandomPerLEDFlicker<Mix<Int<3137>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<255,255,255>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<180,130,0>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,Rgb<100,100,150>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<100,100,150>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,LockupTrL<TransitionEffect<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>>>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrJoin<TrDelay<8000>,TrInstant>,TrFade<3000>,EFFECT_LOCKUP_BEGIN>,TrConcat<TrJoin<TrDelay<50>,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<255,68,0>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<255,68,0>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,68,0>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<255,68,0>>,Int<16000>>,30>,TrSmoothFade<600>>>,LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrConcat<TrJoin<TrDelayX<Mult<IgnitionTime<300>,Int<16384>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,Mix<SmoothStep<NoisySoundLevel,Int<-1>>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>>,TrWipeX<Mult<IgnitionTime<300>,Int<16384>>>>,TrColorCycleX<RetractionTime<0>>,Black>,TransitionEffectL<TrConcat<TrInstant,AlphaL<PulsingL<RgbArg<PREON_COLOR_ARG,Rgb<180,130,0>>,Int<400>>,Bump<Scale<Trigger<EFFECT_PREON,Int<800>,Int<2000>,Int<500>>,Int<0>,Int<16384>>,Int<8000>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<18432>>>,Mix<Bump<Int<16384>,Int<8000>>,Black,RgbArg<PREON_COLOR_ARG,Rgb<180,130,0>>>,TrCenterWipeX<Mult<WavLen<EFFECT_PREON>,Int<4096>>,Int<16384>>,Mix<Bump<Int<16384>,Int<8000>>,Black,PulsingL<RgbArg<PREON_COLOR_ARG,Rgb<180,130,0>>,Int<300>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<10240>>>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RgbArg<POSTOFF_COLOR_ARG,Rgb<180,130,0>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,IntArg<EMITTER_SIZE_ARG,2000>,Sum<IntArg<EMITTER_SIZE_ARG,2000>,Int<3000>>>,Int<-4000>>>,TrDelayX<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,Mix<BatteryLevel,Red,Green>,TrFade<300>>,EFFECT_BATTERY_LEVEL>>>()},

    { "CapAmer;common", "tracks/capamersong.wav",
    /* copyright Fett263 CustomBlade (Primary Blade) OS6 Style
    https://fett263.com/fett263-proffieOS6-style-library.html#CustomBlade
    OS6.7 v4.021
    Single Style
    Split Blade (50/50)
    Default: Rotoscope (Light)
    1: Power Ripple Slow

    Base Color: Rgb<255,0,0> (0)

    --Effects Included--
    Preon Effect: Spectrum Absorb
    Ignition Effect: SparkTip Ignition
    PowerUp Effect: Power Burst Emitter
    Retraction Effect: Fade Out
    CoolDown Effect: Power Burst Center Out
    PostOff Effect: Emitter Cool Off (Preon Size)
    Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
    LightningBlock Effect: Original Lightning Block 
    Drag Effect: Intensity Fire Drag
    Melt Effect: Intensity Melt
    Stab Effect: Normal Stab
    Blast Effect: Blast Wave (Random)
    Clash Effect: Random Clash with Wave
    Swing Effect: Bright Swing (Scaled Full Blade)
    Emitter Effect: Emitter Flare
    Battery Level: Full Blade (Green to Red)
    */
    StylePtr<Layers<Mix<SmoothStep<Int<16384>,Int<3480>>,Stripes<15000,-400,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Stripes<12000,-200,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<20000>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,Stripes<2600,-1600,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<4000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<12000>,Black,RgbArg<ALT_COLOR_ARG,Rgb<255,0,0>>>>>,AlphaL<RgbArg<EMITTER_COLOR_ARG,Rgb<100,100,150>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,5726>,Int<-6000>>>,AlphaL<RgbArg<SWING_COLOR_ARG,Rgb<100,100,150>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<IgnitionTime<300>>,TrInstant>,AlphaL<Stripes<5000,-2500,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<7710>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<3855>,Black,RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,150>>>>,SmoothStep<IntArg<EMITTER_SIZE_ARG,5726>,Int<-500>>>,TrFade<500>>,EFFECT_IGNITION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<RetractionTime<0>>,TrInstant>,Remap<CenterDistF<>,Stripes<5000,-2500,RgbArg<RETRACTION_COLOR_ARG,Rgb<100,100,150>>,Mix<Int<7710>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<3855>,Black,RgbArg<RETRACTION_COLOR_ARG,Rgb<100,100,150>>>>>,TrFade<800>>,EFFECT_RETRACTION>,TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<100,100,150>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,TransitionEffectL<TrWaveX<RgbArg<BLAST_COLOR_ARG,Rgb<255,255,255>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<100>,Int<400>>,Int<100>,Scale<EffectPosition<EFFECT_BLAST>,Int<100>,Int<400>>,Scale<EffectPosition<EFFECT_BLAST>,Int<28000>,Int<8000>>>,EFFECT_BLAST>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,Rgb<100,100,150>>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<ClashImpactF<>,Int<28000>,Int<8000>>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<100,100,150>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,LockupTrL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<100,100,150>>,LayerFunctions<Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<100,100,150>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<100,100,150>>,Int<16000>>,30>,TrSmoothFade<600>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,LockupTrL<AlphaL<Stripes<2000,4000,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>,Mix<Sin<Int<50>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<4096>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<Stripes<2000,3000,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>,Mix<Sin<Int<30>>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>,Mix<Int<8192>,Black,RgbArg<DRAG_COLOR_ARG,Rgb<100,100,150>>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,28000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrJoin<TrDelay<4000>,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,28000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<100,100,150>>,IgnitionTime<300>>,TrFadeX<RetractionTime<0>>,Black>,TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrSparkX<RotateColorsX<Saw<Int<6>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Int<200>,Int<500>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<6144>>>,TransitionLoopL<TrSparkX<RotateColorsX<Saw<Int<6>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Int<300>,Int<300>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<8192>>>,TransitionLoopL<TrSparkX<RotateColorsX<Saw<Int<6>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,Int<400>,Int<100>,Int<32768>>>,TrDelayX<Mult<WavLen<EFFECT_PREON>,Int<12288>>>,AlphaL<RotateColorsX<Saw<Int<6>>,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,SmoothStep<IntArg<PREON_SIZE_ARG,11938>,Int<-4000>>>,TrBoingX<Mult<WavLen<EFFECT_PREON>,Int<6144>>,5>>,EFFECT_PREON>,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,SmoothStep<IntArg<PREON_SIZE_ARG,11938>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Orange,SmoothStep<IntArg<PREON_SIZE_ARG,11938>,Int<-4000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>,AlphaL<Red,SmoothStep<IntArg<PREON_SIZE_ARG,11938>,Int<-2000>>>,TrFadeX<Mult<Scale<IsLessThan<WavLen<EFFECT_POSTOFF>,Int<200>>,WavLen<EFFECT_POSTOFF>,Int<4000>>,Int<10923>>>>,EFFECT_POSTOFF>,TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrInstant>,Mix<BatteryLevel,Red,Green>,TrFade<300>>,EFFECT_BATTERY_LEVEL>>>()},


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
