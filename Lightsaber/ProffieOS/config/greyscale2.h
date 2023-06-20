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
#endif 

#ifdef CONFIG_PROP
#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {

    /*

    { "Mercenary;common", "common/tracks/venus.wav",
    StylePtr<Layers<

    //Base Fett263 Smoke Blade style
    StripesX<Sin<Int<12>,Int<3000>,Int<7000>>,Scale<SwingSpeed<100>,Int<75>,Int<125>>,StripesX<Sin<Int<10>,Int<1000>,Int<3000>>,Scale<SwingSpeed<100>,Int<75>,Int<100>>,Pulsing<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<15,14,0>>,1200>,Mix<SwingSpeed<200>,RotateColorsX<Variation,Rgb<90,87,0>>,Black>>,RotateColorsX<Variation,Rgb<40,40,0>>,Pulsing<RotateColorsX<Variation,Rgb<36,33,0>>,StripesX<Sin<Int<10>,Int<2000>,Int<3000>>,Sin<Int<10>,Int<75>,Int<100>>,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<60,58,0>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<90,88,0>>,RotateColorsX<Variation,Rgb<5,5,0>>,3000>>,

    //Underlying Fett263 Smoke Blade Fire layer
    AlphaL<StyleFire<RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<2,2,0>>,0,1,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<10,2000,2>,FireConfig<0,0,25>>,Int<10000>>,
    
    //Fett263 Ripple swing effect
    AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Yellow>,RotateColorsX<Variation,Rgb<44,42,0>>,Pulsing<RotateColorsX<Variation,Rgb<22,20,0>>,Black,800>>,SwingSpeed<375>>,
    
    //Fett263 Bright hard swing effect
    AlphaL<RotateColorsX<Variation,LemonChiffon>,Scale<IsLessThan<SwingSpeed<675>,Int<13600>>,Scale<SwingSpeed<750>,Int<-17300>,Int<32768>>,Int<0>>>,
    
    //Fett263 Responsive Intensity Lockup
    LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<200>>,StripesX<Int<1800>,Scale<NoisySoundLevel,Int<-3500>,Int<-5000>>,Mix<Int<6425>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>,RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<12850>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>>,
    TrConcat<TrExtend<50,TrInstant>,Mix<IsLessThan<ClashImpactF<>,Int<26000>>,RgbArg<LOCKUP_COLOR_ARG,White>,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<20000>,Int<60000>>>>>,TrExtend<3000,TrFade<300>>,AlphaL<AudioFlicker<RgbArg<LOCKUP_COLOR_ARG,White>,Mix<Int<10280>,Black,RgbArg<LOCKUP_COLOR_ARG,White>>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Int<13000>>>,TrFade<3000>>,
    TrConcat<TrInstant,AlphaL<RgbArg<LOCKUP_COLOR_ARG,White>,Int<0>>,TrWaveX<RgbArg<LOCKUP_COLOR_ARG,White>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>>,SaberBase::LOCKUP_NORMAL>,
    
    //Fett263 Responsive Lightning Block
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,White>,AudioFlicker<RgbArg<LB_COLOR_ARG,White>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,White>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,White>,Int<16000>>,30>,TrSmoothFade<600>>>,
    
    //Fett263 Sparking Emitter Flare
    AlphaL<RotateColorsX<Variation,LemonChiffon>,SmoothStep<Scale<SlowNoise<Int<2750>>,Int<1750>,Int<3750>>,Int<-4000>>>,
    
    //Responsive Stab
    ResponsiveStabL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,DeepPink>>,TrWipeInX<Percentage<WavLen<EFFECT_STAB>,50>>,TrFadeX<Percentage<WavLen<EFFECT_STAB>,50>>>,
    
    //Fett263 Multi-blast, blaster reflect cycles through different responsive effects
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<RgbArg<BLAST_COLOR_ARG,White>,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<RgbArg<BLAST_COLOR_ARG,White>,200,200>,ResponsiveBlastFadeL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<RgbArg<BLAST_COLOR_ARG,White>,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    
    //Fett263 Real Clash
    Mix<IsLessThan<ClashImpactF<>,Int<26000>>,TransitionEffectL<TrConcat<TrInstant,AlphaL<RgbArg<CLASH_COLOR_ARG,White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>,Scale<ClashImpactF<>,Int<12000>,Int<60000>>>>,TrFadeX<Scale<ClashImpactF<>,Int<200>,Int<400>>>>,EFFECT_CLASH>,TransitionEffectL<TrWaveX<RgbArg<CLASH_COLOR_ARG,White>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Int<100>,Scale<ClashImpactF<>,Int<100>,Int<400>>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-10000>>>>,EFFECT_CLASH>>,
    
    //Fett263 Unstable bright ignition effect
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<100,100,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,60,80>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<110,115,140>>,RotateColorsX<Variation,Rgb<60,60,80>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,128,128>>,RotateColorsX<Variation,Rgb<60,60,80>>>>,TrFadeX<Percentage<WavLen<>,65>>>,EFFECT_IGNITION>,
    
    //Fett263 Bright Humpflicker retraction effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFadeX<Percentage<WavLen<>,125>>>,EFFECT_RETRACTION>,

    //Fett263 Intensity Drag
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,White>>,SmoothStep<IntArg<DRAG_SIZE_ARG,27500>,Int<5000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,White>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,29250>,Int<5000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    
    //Fett263 Responsive Intensity Melt
    LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,OrangeRed,DarkOrange>,Mix<TwistAngle<>,OrangeRed,Orange>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,26000>,Int<6000>>>,TrConcat<TrWipeIn<100>,AlphaL<Red,SmoothStep<Int<29000>,Int<8000>>>,TrExtend<2000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<29000>,Int<8000>>>,TrFade<3000>>,TrFade<250>,SaberBase::LOCKUP_MELT>,
    
    //Fett263 Power Save, if using Fett263's prop file hold AUX and click PWR while ON (pointing up) to dim blade in 25% increments.
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,

    //Fett263 White Spark Tip ignition and Color Cycle retraction
    InOutTrL<TrJoin<TrWipeX<Percentage<WavLen<EFFECT_IGNITION>,8>>,TrWaveX<White,Percentage<WavLen<EFFECT_IGNITION>,25>,Int<300>,Percentage<WavLen<EFFECT_IGNITION>,8>,Int<0>>>,TrColorCycle<950,7500>>,
    
    //Fett263 optional/alternate Passive Battery Monitor: on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    
    //Fett263 On-Demand Battery Level: if using Fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    
    //Absorby charge-up preon
    TransitionEffectL<TrConcat<TrDelayX<Percentage<WavLen<>,33>>,TransitionLoopL<TrJoin<TrWipeIn<142>,TrSparkX<RotateColorsX<Variation,LemonChiffon>,Int<425>,Int<142>,Int<32768>>>>,TrDelayX<Percentage<WavLen<>,67>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Percentage<WavLen<>,33>,Percentage<WavLen<>,67>,Int<0>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,HotPink>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,LightPink>,RotateColorsX<Variation,LemonChiffon>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,DeepPink>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Yellow>>>,RotateColorsX<Variation,LemonChiffon>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-350>,Int<17500>>,Int<-4000>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Black,SmoothStep<Sin<Int<10>,Int<16500>,Int<14500>>,Sin<Int<7>,Int<10500>,Int<9500>>>>,TrDelayX<WavLen<>>>,EFFECT_PREON>
    >>(), "mercenary"},


    { "Analog;common", "common/tracks/venus.wav",
    StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb16<0,38402,65535>>,RotateColorsX<Variation,Rgb<0,85,200>>>,
    //Ice blue audioflicker
    AlphaL<RotateColorsX<Variation,Rgb16<882,65535,31206>>,SwingSpeed<500>>,
    //Bright cyan color swing
    AlphaL<Stripes<2500,-4000,RotateColorsX<Variation,Rgb16<0,38402,65535>>,RotateColorsX<Variation,Rgb<0,26,60>>,Pulsing<RotateColorsX<Variation,Rgb<0,13,30>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    //Hard swing ripple effect
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<600>,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<1000>>,Stripes<1500,2000,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb16<0,65535,30086>>>,Stripes<1500,-2500,RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb16<0,65535,30086>>>>,Int<18000>>,TrFade<800>,AlphaL<Mix<SmoothStep<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<1000>>,Stripes<1500,1000,RotateColorsX<Variation,Rgb16<1514,65535,52727>>,RotateColorsX<Variation,Rgb16<3934,65535,38402>>>,Stripes<1500,-1250,RotateColorsX<Variation,Rgb16<1514,65535,52727>>,RotateColorsX<Variation,Rgb16<3934,65535,38402>>>>,Int<18000>>,TrFade<1100>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup with click calibration effect
    //AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<2100>>,SaberBase::LOCKUP_NORMAL>,
    //Alternate lockup ending with white fade out, replace the second AlphaL line above (ending in LOCKUP_NORMAL)
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb16<0,65535,30086>>,SmoothStep<Scale<SlowNoise<Int<2300>>,Int<1200>,Int<4500>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1000>>,EFFECT_IGNITION>,
    //Bright HumpFlicker ignition effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<90,180,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    //Bright HumpFlicker retraction effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrConcat<TrWipe<200>,AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,0,128>>>,TrWipe<100>,Black,TrBoing<550,2>>,TrColorCycle<790>>,
    //Glitch out ignition and cycle down retraction
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<RotateColorsX<Variation,Rgb16<0,38402,65535>>,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2200>>,Int<1500>,Int<5000>>,Int<-4000>>>,TrFade<1400>,AlphaL<RotateColorsX<Variation,Rgb16<0,11150,20996>>,Bump<Int<0>,Int<10000>>>,TrFade<1500>,AlphaL<Rgb16<20393,20393,20393>,Bump<Int<0>,Int<7000>>>,TrFade<2100>>,EFFECT_RETRACTION>,
    //Retraction cool down effect
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrFade<100>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,500>,Bump<Int<0>,Int<6000>>>,TrBoing<600,9>>,EFFECT_PREON>
    //Clickity preon
    >>(), "analog"},

    { "Apocalypse;common", "common/tracks/venus.wav",
    StylePtr<Layers<
    Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,Mix<Sin<Int<30>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<30,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,25,0>>,RotateColorsX<Variation,Rgb<60,15,0>>>,300>,RotateColorsX<Variation,Rgb<30,2,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>>,HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<125,0,0>>,40>>,
    //Swing responsive humpflicker/rotating red/orange unstable base, unstable takes over the blade the harder you swing
    //HumpFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<128,0,0>>,50>,
    //Alternate plain humpflicker
    AlphaL<AlphaL<AudioFlickerL<RotateColorsX<Variation,Rgb16<65535,8729,0>>>,SwingSpeed<350>>,SmoothStep<Scale<SwingSpeed<450>,Int<29000>,Int<9500>>,Int<16000>>>,
    //Responsive edge audioflicker swing - starts at the tip and takes over the blade the harder you swing
    LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,150,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<Moccasin,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<500>>,TrConcat<TrInstant,White,TrFade<600>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,25,0>>,RotateColorsX<Variation,Rgb<60,15,0>>>,300>,RotateColorsX<Variation,Rgb<30,2,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,TrFade<50>,RotateColorsX<Variation,Rgb16<65535,8729,0>>,TrFade<525>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,25,0>>,RotateColorsX<Variation,Rgb<60,15,0>>>,300>,RotateColorsX<Variation,Rgb<30,2,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,TrFade<50>,RotateColorsX<Variation,Rgb16<35913,7294,0>>,TrFade<250>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,25,0>>,RotateColorsX<Variation,Rgb<60,15,0>>>,300>,RotateColorsX<Variation,Rgb<30,2,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,TrFade<100>,RotateColorsX<Variation,Rgb16<20393,1818,0>>,TrBoing<950,3>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup with unstable cooldown
    //AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrJoinR<TrWipe<100>,TrWipeIn<100>>,White,TrFade<3000>>,SaberBase::LOCKUP_NORMAL>,
    //Alternate normal endlock effect
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    ResponsiveStabL<RotateColorsX<Variation,Orange>>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    //ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    //Alternate responsive blast
    ResponsiveClashL<TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive Clash
    //ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Alternate white clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Orange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<70,25,5>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<75,20,5>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<155,25,0>>,RotateColorsX<Variation,Rgb<65,15,0>>>>,TrFade<2500>,Stripes<3000,-2250,RotateColorsX<Variation,DarkOrange>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<195,15,0>>,RotateColorsX<Variation,Rgb<50,15,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<85,15,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<155,25,0>>,RotateColorsX<Variation,Rgb<95,15,0>>>>,TrFade<1000>,Stripes<3000,-1500,RotateColorsX<Variation,Rgb16<65535,8729,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<195,10,0>>,RotateColorsX<Variation,Rgb<55,5,0>>>,BrownNoiseFlicker<RotateColorsX<Variation,OrangeRed>,RotateColorsX<Variation,Rgb<185,10,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<255,13,0>>,RotateColorsX<Variation,Rgb<105,3,0>>>>,TrFade<2500>>,EFFECT_IGNITION>,
    //Unstable ignition
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<255,75,0>>,40>,TrFade<500>>,EFFECT_RETRACTION>,
    //Humpflicker retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,175,250>,TrColorCycle<500>>,
    //Spark tip ignition, cycle down retraction
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<500>,Int<5500>>,Int<-4000>>>,TrFade<1100>>,EFFECT_RETRACTION>,
    //White flicker retraction effect
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<1600>,AlphaL<RotateColorsX<Variation,Orange>,Bump<Int<0>,Int<8000>>>,TrFade<1400>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Emitter cool off retraction effect
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<2000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Red>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb16<14386,0,0>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Red>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Red>>>,DarkOrange,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-1000>,Int<25000>>,Int<-4000>>>,TrDelay<6500>>,EFFECT_PREON>,
    //Noise responsive preon
    TransitionEffectL<TrConcat<TrDelay<3000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<115>,Int<400>,Int<250>,Int<0>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<215>,Int<300>,Int<395>,Int<0>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Red>,Int<345>,Int<200>,Int<500>,Int<0>>>,TrDelay<1500>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<6000>>>,TrBoing<500,2>>,EFFECT_PREON>,
    //Charge up, wave out preon
    TransitionEffectL<TrConcat<TrFade<1500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Red>,10>,Bump<Int<0>,Int<4000>>>,TrFade<2000>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Orange>,15>,Bump<Int<0>,Int<5000>>>,TrFade<2500>,AlphaL<HumpFlickerL<White,20>,Bump<Int<0>,Int<6000>>>,TrBoing<500,2>>,EFFECT_PREON>
    //Emitter heat up preon
    >>(), "apocalypse"},

    { "Assassin;common", "common/tracks/venus.wav",
    StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>,50>,
    //Green humpflicker
    AlphaL<Stripes<2500,-2750,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<25,60,0>>,Pulsing<RotateColorsX<Variation,Rgb<0,30,0>>,Black,800>>,SwingSpeed<375>>,
    //Swing effect, rippling green
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb16<21301,65535,0>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<38402,65535,3934>>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<38402,65535,3934>>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<500>>,EFFECT_IGNITION>,
    //Unstable ignition
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb16<54757,65535,0>>>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Bright retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,250>,TrWipeInSparkTip<White,656>>,
    //Spark tip ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "assassin"},

    { "Coda;common", "tracks/venus.wav",
    StylePtr<Layers<
    Mix<Sin<Int<3>>,AudioFlicker<RotateColorsX<Variation,DodgerBlue>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,55,165>>,RotateColorsX<Variation,Rgb<0,85,115>>,RotateColorsX<Variation,Rgb<0,65,145>>,RotateColorsX<Variation,Rgb<0,30,185>>>>,AudioFlicker<RotateColorsX<Variation,Rgb<0,155,255>>,Stripes<5000,-90,RotateColorsX<Variation,Rgb<0,95,170>>,RotateColorsX<Variation,Rgb<0,115,215>>,RotateColorsX<Variation,Rgb<0,145,145>>,RotateColorsX<Variation,Rgb<0,65,225>>>>>,
    //Rotates   ^3 times per minute between DodgerBlue and DeepSkyBlue with subtle Cyan/Blue audioflicker
    //AudioFlicker<RotateColorsX<Variation,DeepSkyBlue>,RotateColorsX<Variation,Rgb<0,95,195>>>,
    //Alternate DeepSkyBlue with very subtle audioflicker
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black,300>,SwingSpeed<400>>,
    //Unstable swing
    AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,DeepSkyBlue>,Black>,Black,RotateColorsX<Variation,DeepSkyBlue>,Black>,SwingSpeed<525>>,
    //Unstable ripple swing
    LockupTrL<Layers<
    AlphaL<AudioFlickerL<Rgb<255,240,80>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    AlphaL<LemonChiffon,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<875>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup effect with screeching humpflicker endlock
    //LockupTrL<Layers<
    //AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    //AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<4000>>,SaberBase::LOCKUP_NORMAL>,
    //Alternate standard lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    ResponsiveStabL<RotateColorsX<Variation,Yellow>>,
    //Responsive stab
    //ResponsiveStabL<Red>,
    //Alternate responsive stab, no color change
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    //ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    //Alternate responsive blast
    ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive Clash
    //ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Alternate white clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<90,180,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,26,60>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<90,180,255>>,RotateColorsX<Variation,Rgb<0,26,60>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<0,42,128>>,RotateColorsX<Variation,Rgb<0,26,60>>>>,TrFade<450>,HumpFlickerL<AlphaL<RotateColorsX<Variation,Rgb<90,180,255>>,Int<19000>>,25>,TrFade<2875>>,EFFECT_IGNITION>,
    //Stabilize ignition effect
    TransitionEffectL<TrConcat<TrFade<1125>,RotateColorsX<Variation,Rgb<90,180,255>>,TrInstant>,EFFECT_RETRACTION>,
    //Slow brighten retraction effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipe<500>,TrWipeIn<1125>>,
    //Standard ignition/retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,10>,Bump<Int<0>,Int<3000>>>,TrFade<350>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,15>,Bump<Int<0>,Int<5000>>>,TrFade<450>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,20>,Bump<Int<0>,Int<7000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,DeepSkyBlue>,25>,Bump<Int<0>,Int<10500>>>,TrBoing<150,1>>,EFFECT_PREON>
    //Overload preon effect
    >>(), "coda"},

    { "Crispity;common", "tracks/venus.wav",
    StylePtr<Layers<
    StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<11805,0,1587>>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
    //Unstable red/pink
    TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,DeepPink>,SwingSpeed<400>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,DeepPink>,SwingSpeed<400>>,TrFade<800>>,EFFECT_FORCE>,
    //Force effect, temporarily allows color change based on swing speed
    AlphaL<AudioFlickerL<RotateColorsX<Variation,DeepPink>>,SwingSpeed<400>>,
    //Swing effect, audioflicker, Deep Pink connects the tip and emitter when swinging
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1500>,Int<4500>>,Int<-6000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Orange>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<255,150,150>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    //Unstable ignition effect
    AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<28000>,Int<33000>>,Int<10000>>>,
    //Sparking tip flare
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,100>,TrColorCycle<1065>>,
    //Spark tip ignition, cycle down retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Sin<Scale<Trigger<EFFECT_RETRACTION,Int<3000>,Int<1000>,Int<500>>,Int<70>,Int<550>>>,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb16<65535,0,2716>>>,Bump<Scale<Trigger<EFFECT_PREON,Int<3000>,Int<1000>,Int<500>>,Int<41000>,Int<32768>>>>,TrDelay<3000>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<520>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<520>,Int<550>,Int<520>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<420>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<420>,Int<450>,Int<420>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<340>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<340>,Int<430>,Int<340>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<300>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<300>,Int<400>,Int<300>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<240>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<240>,Int<380>,Int<240>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<210>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<210>,Int<360>,Int<210>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<190>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<190>,Int<340>,Int<190>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<170>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<170>,Int<320>,Int<170>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<160>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<160>,Int<300>,Int<160>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<150>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<150>,Int<250>,Int<150>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<130>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<130>,Int<150>,Int<130>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Bump<Int<0>,Int<4000>>>,TrFade<100>>,TrWaveX<RotateColorsX<Variation,Rgb16<65535,0,2716>>,Int<100>,Int<100>,Int<100>,Int<0>>>,AlphaL<Black,Int<0>>,TrJoin<TrConcat<TrInstant,AlphaL<RotateColorsX<Variation,DeepPink>,Bump<Int<0>,Int<4000>>>,TrFade<70>>,TrWaveX<RotateColorsX<Variation,DeepPink>,Int<70>,Int<500>,Int<70>,Int<0>>>,Black,TrInstant>,EFFECT_PREON>
    //Preon effect, HUGE thanks to /u/NoSloppy for this!
    >>(), "crispity"},

    */

    { "Deadlink;common", "tracks/venus.wav",
    StylePtr<Layers<
    HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<150,0,150>>,50>,
    //Magenta HumpFlicker
    AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb16<12482,0,18076>>,Pulsing<RotateColorsX<Variation,Rgb<10,0,26>>,Black,800>>,SwingSpeed<350>>,
    //Ripple swing effect
    //AlphaL<AudioFlickerL<Stripes<2500,-3000,RotateColorsX<Variation,DeepPink>,RotateColorsX<Variation,Rgb16<12482,0,18076>>,Pulsing<RotateColorsX<Variation,Rgb<10,0,26>>,Black,800>>>,SwingSpeed<300>>,
    //Alternate audioflicker ripple swing effect
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb16<33124,0,65535>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3500>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrDelay<875>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,0,255>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<250>,HumpFlicker<RotateColorsX<Variation,Magenta>,RotateColorsX<Variation,Rgb<80,0,80>>,50>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,DeepPink>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<21,0,52>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<160,0,255>>,RotateColorsX<Variation,Rgb<21,0,52>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<42,0,105>>,RotateColorsX<Variation,Rgb<21,0,52>>>>,TrFade<1500>>,EFFECT_IGNITION>,
    //Unstable ignition effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<180,60,255>>,40>,TrFade<2000>>,EFFECT_RETRACTION>,
    //Bright HumpFlicker retraction effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrConcat<TrWipeIn<200>,RandomBlink<30000,RotateColorsX<Variation,Rgb16<65535,13655,65535>>>,TrWipeIn<200>,Mix<SmoothStep<Scale<SlowNoise<Int<30000>>,Int<1000>,Int<6000>>,Int<-3000>>,Black,RotateColorsX<Variation,Rgb16<65535,13655,65535>>>,TrDelay<400>,Mix<SmoothStep<Int<4000>,Int<-3000>>,Black,White>,TrWipe<175>>,TrColorCycle<2000>>,
    //Lightning strike ignition, cycle down retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "deadlink"},


    { "Decay;common", "tracks/venus.wav",
    StylePtr<Layers<
    StripesX<Int<3500>,Int<1200>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Mix<Sin<Int<23>>,RotateColorsX<Variation,Rgb<52,0,125>>,RotateColorsX<Variation,Rgb<84,0,210>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<115,15,220>>,RotateColorsX<Variation,Rgb<95,0,210>>>,Mix<Sin<Int<18>>,RotateColorsX<Variation,Rgb<26,0,42>>,RotateColorsX<Variation,Rgb<60,0,132>>>>,
    //Bright purple absorb effect
    //StripesX<Int<3500>,Int<1200>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Mix<Sin<Int<23>>,RotateColorsX<Variation,Rgb<52,0,125>>,RotateColorsX<Variation,Rgb<84,0,210>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<115,0,220>>,RotateColorsX<Variation,Rgb<95,0,210>>>,Mix<Sin<Int<18>>,RotateColorsX<Variation,Rgb<26,0,42>>,RotateColorsX<Variation,Rgb<60,0,132>>>>,
    //Alternate darker purple absorb effect, color change friendly (for reds and such)
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black,300>,SwingSpeed<400>>,
    //Unstable swing
    AlphaL<Stripes<1000,2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,Black,RotateColorsX<Variation,Rgb<95,0,210>>,Black>,SwingSpeed<500>>,
    //Ripple down swing
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    //Bright hard swings
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>,StripesX<Int<3500>,Int<1200>,Mix<Sin<Int<20>>,RotateColorsX<Variation,Rgb<95,0,210>>,RotateColorsX<Variation,Rgb<75,0,165>>>,Mix<Sin<Int<23>>,RotateColorsX<Variation,Rgb<52,0,125>>,RotateColorsX<Variation,Rgb<84,0,210>>>,Mix<Sin<Int<16>>,RotateColorsX<Variation,Rgb<115,15,220>>,RotateColorsX<Variation,Rgb<95,0,210>>>,Mix<Sin<Int<18>>,RotateColorsX<Variation,Rgb<26,0,42>>,RotateColorsX<Variation,Rgb<60,0,132>>>>,TrFade<1225>,RotateColorsX<Variation,Rgb<160,60,255>>,TrFade<250>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup with reset
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb<160,60,255>>,SmoothStep<Scale<SlowNoise<Int<1750>>,Int<1500>,Int<4500>>,Int<-6000>>>,
    //Sparking emitter flare
    //AlphaL<RotateColorsX<Variation,Rgb16<45025,0,65535>>,SmoothStep<Scale<SlowNoise<Int<1750>>,Int<1500>,Int<4500>>,Int<-6000>>>,
    //Alternate darker sparking emitter flare, color change friendly (for reds and such)
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb<160,60,255>>,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<175,80,255>>,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1650>>,EFFECT_IGNITION>,
    //Bright unstable ignition
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<160,60,255>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    //Bright HumpFlicker retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeInSparkTip<White,200>,TrWipeInSparkTip<White,1125>>,
    //Spark tip in ignition and retraction
    //InOutTrL<TrWipeSparkTip<White,200>,TrWipeInSparkTip<White,1125>>,
    //Alternate spark tip ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,40>,TrWipe<150>,HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,40>,TrBoing<350,2>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<5000>>>,TrFade<625>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<9000>>>,TrFade<625>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,40>,Bump<Int<0>,Int<13000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,69>,Bump<Int<0>,Int<18000>>>,TrFade<750>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,69>,Bump<Int<0>,Int<23000>>>,TrFade<750>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,30>,Bump<Int<0>,Int<7000>>>,TrFade<500>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<95,0,210>>,50>,Bump<Int<0>,Int<19000>>>,TrBoing<1950,9>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrInstant,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<500>,Int<200>,Int<400>,Int<32768>>>,TrDelay<1250>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<315>,Int<215>,Int<32768>>>,TrDelay<1000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<115>,Int<375>,Int<115>,Int<32768>>>,TrDelay<1250>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<1500>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<1750>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<300>,Int<300>,Int<32768>>>,TrDelay<2000>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<300>,Int<315>,Int<215>,Int<32768>>>,TrDelay<450>,TransitionLoopL<TrWaveX<RotateColorsX<Variation,Rgb<95,0,210>>,Int<100>,Int<400>,Int<100>,Int<32768>>>,TrDelay<1450>,AlphaL<RotateColorsX<Variation,Rgb<95,0,210>>,Bump<Int<0>,Int<6000>>>,TrBoing<1450,5>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<4350>,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<5000>,Int<3000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<33124,0,65535>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<56306,0,65535>>,RotateColorsX<Variation,Rgb16<21919,0,22863>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Rgb16<33124,0,65535>>,RotateColorsX<Int<2750>,RotateColorsX<Variation,Rgb16<33124,0,65535>>>>,RotateColorsX<Variation,Rgb16<42753,14386,65535>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-5000>,Int<42500>>,Int<-4000>>>,TrDelay<7750>>,EFFECT_PREON>
    //Life force drain preon
    >>(), "decay"},


    { "EngineGrip;common", "tracks/venus.wav",
    StylePtr<Layers<
    StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<18,13,0>>,RotateColorsX<Variation,Rgb<43,31,0>>>,300>,RotateColorsX<Variation,Rgb<56,40,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,
    //Unstable yellow
    AlphaL<AudioFlickerL<RotateColorsX<Variation,Rgb16<65535,38402,0>>>,SwingSpeed<400>>,
    //Swing effect, audioflicker orange swing
    AlphaL<Stripes<3000,-1600,Mix<Sin<Int<30>>,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Orange>>,Mix<Sin<Int<30>>,RotateColorsX<Variation,Rgb<90,0,0>>,RotateColorsX<Variation,Rgb<60,30,0>>>,Mix<Sin<Int<26>>,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,OrangeRed>>,Mix<Sin<Int<24>>,RotateColorsX<Variation,Rgb<60,30,0>>,RotateColorsX<Variation,Rgb<90,0,0>>>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<12000>>>,
    //Color Change Responsive Fire Spark
    //AlphaL<Stripes<3000,-1600,Mix<Sin<Int<30>>,Red,Orange>,Mix<Sin<Int<30>>,Rgb<90,0,0>,Rgb<60,30,0>>,Mix<Sin<Int<26>>,DarkOrange,OrangeRed>,Mix<Sin<Int<24>>,Rgb<60,30,0>,Rgb<90,0,0>>>,Bump<Scale<SwingSpeed<400>,Int<1000>,Int<34000>>,Int<12000>>>,
    //Alternate Responsive Fire Spark, no color change
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Orange>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3500>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    TransitionEffectL<TrConcat<TrDelay<450>,Layers<
        AlphaL<TransitionLoopL<TrConcat<TrWaveX<White,Int<300>,Int<400>,Int<300>,Int<32768>>>>,SmoothStep<Int<16384>,Int<-100>>>,
        AlphaL<TransitionLoopL<TrConcat<TrWaveX<White,Int<300>,Int<400>,Int<300>,Int<0>>>>,SmoothStep<Int<16384>,Int<100>>>>,TrDelay<300>>,EFFECT_BLAST>,
    //Timed Blaster reflect. This is non-responsive and always starts in the middle of the blade, but it matches up with the timed blaster bolts for Engine Grip. However, it seems to make the saber freeze up a bit too much for my liking, and if you spam it fast enough it might crash and you'll need to take the battery out/toggle the kill switch.
    //EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Alternate Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,OrangeRed>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<45,32,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,36321,6957>>,RotateColorsX<Variation,Rgb<45,32,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<90,65,0>>,RotateColorsX<Variation,Rgb<45,32,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    //Bright unstable ignition
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb<230,180,80>>,40>,TrFade<1200>>,EFFECT_RETRACTION>,
    //Bright HumpFlicker retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrJoinR<TrWipe<200>,TrWipeIn<200>>,TrColorCycle<2250>>,
    //Center Out ignition, Cycle Down retraction
    //InOutTrL<TrWipeSparkTip<White,200>,TrColorCycle<2250>>,
    //Alternate Spark Tip ignition and Cycle Down retraction
    TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<875>,AlphaL<RotateColorsX<Variation,Orange>,Bump<Int<0>,Int<8000>>>,TrFade<1000>,AlphaL<RotateColorsX<Variation,Red>,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Color Change Cool Down Retraction
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<White,Bump<Int<0>,Int<10000>>>,TrFade<875>,AlphaL<Orange,Bump<Int<0>,Int<8000>>>,TrFade<1000>,AlphaL<Red,Bump<Int<0>,Int<6000>>>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Alternate Cool Down Retraction, no color change
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,Layers<
        AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<180,130,0>>,Int<50>,Int<200>,Int<75>,Int<0>>,Black,TrDelay<50>>>,SmoothStep<Int<16384>,Int<-100>>>,
        AlphaL<TransitionLoopL<TrConcat<TrWaveX<RotateColorsX<Variation,Rgb<180,130,0>>,Int<50>,Int<200>,Int<75>,Int<32768>>,Black,TrDelay<50>>>,SmoothStep<Int<16384>,Int<100>>>>,TrDelay<1220>>,EFFECT_PREON>,
    TransitionEffectL<TrConcat<TrDelay<300>,AlphaL<RotateColorsX<Variation,Rgb<90,65,0>>,Bump<Int<16384>,Int<4000>>>,TrFade<500>,AlphaL<AudioFlickerL<RotateColorsX<Variation,Rgb<180,130,0>>>,Bump<Int<16384>,Int<16000>>>,TrDelay<700>>,EFFECT_PREON>
    //Center absorb preon
    //TransitionEffectL<TrConcat<TrInstant,StyleFire<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<45,32,0>>,0,6,FireConfig<2,1200,5>,FireConfig<0,0,0>,FireConfig<0,0,0>,FireConfig<2,1200,5>>,TrWipe<750>,StyleFire<RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<45,32,0>>,0,6,FireConfig<2,1200,5>,FireConfig<0,0,0>,FireConfig<0,0,0>,FireConfig<2,1200,5>>,TrBoing<250,2>>,EFFECT_PREON>
    //Alternate glitchy fire preon, make sure to comment out both transition lines and both alpha lines above
    >>(), "engine grip"},


    { "Exalted;common", "tracks/venus.wav",
    StylePtr<Layers<
    Mix<SwingSpeed<400>,StyleFire<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RandomPerLEDFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>>,300>,RotateColorsX<Variation,Rgb<80,0,0>>,0,6,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>,FireConfig<10,1000,2>>,AudioFlicker<RotateColorsX<Variation,Rgb16<65535,8357,0>>,RotateColorsX<Variation,Rgb16<42307,1982,0>>>>,
    //Unstable red with blood orange audioflicker swing effects
    AlphaL<Stripes<2500,-3000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,Pulsing<RotateColorsX<Variation,Rgb<30,0,0>>,Black,800>>,Scale<IsLessThan<SwingSpeed<600>,Int<13600>>,Scale<SwingSpeed<600>,Int<-19300>,Int<32768>>,Int<0>>>,
    //Hard swings cause red to ripple up the blade
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SmoothStep<Scale<SlowNoise<Int<3000>>,Int<2000>,Int<3500>>,Int<-3000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Orange>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<65535,8357,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,0,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<60,0,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,0,0>>,RotateColorsX<Variation,Rgb<60,0,0>>>>,TrFade<1200>>,EFFECT_IGNITION>,
    //Unstable fiery ignition effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,250>,TrColorCycle<1450>,Black>,
    //Spark tip ignition, cycle down retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    //,TransitionEffectL<TrConcat<TrFade<100>,AlphaL<Pulsing<Rgb<120,120,165>,Rgb<50,50,80>,500>,Bump<Int<0>,Int<6000>>>,TrBoing<600,9>>,EFFECT_PREON>
    //Optional Clickity Preon, I recommend using Analog's preon :) Make sure to leave the comma at the beginning in if you're using the on demand battery level
    >>(), "exalted"},


    { "Grey;common", "tracks/venus.wav",
    StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,RotateColorsX<Variation,Rgb<50,50,75>>>,
    //White audioflicker
    EffectSequence<EFFECT_FORCE,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,White>,Black,300>,SwingSpeed<450>>,AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,SwingSpeed<450>>>,
    //Force toggleable swing effect. Trigger a force effect to alternate between a ripple swing and an unstable swing (the two below)
    //AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<100,100,150>>,Black>,White,RotateColorsX<Variation,Rgb<100,100,150>>,White>,SwingSpeed<450>>,
    //Alternate swing effect, white ripple
    //AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,White>,Black,300>,SwingSpeed<450>>,
    //Alternate swing effect, unstable white
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<700>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    //LockupTrL<Layers<
    //  AlphaL<AudioFlickerL<Rgb<255,100,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
    //  AlphaL<Red,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<5000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<700>>,SaberBase::LOCKUP_NORMAL>,
    //Alternate responsive lockup, "beskar" heat up. Note: right now this is really just a placeholder until OS6 brings the intensity lockup, which will really give it a Mando feel if that's what you're after
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    ResponsiveStabL<Blue>,
    //Responsive stab, ice blue
    //ResponsiveStabL<White>,
    //Alternate responsive stab, white
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<500>,EFFECT_LOCKUP_BEGIN>,TrFade<1000>,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<575>,TransitionEffect<Rgb16<24485,24485,24485>,Rgb16<17521,23829,23829>,TrInstant,TrFade<100>,EFFECT_LOCKUP_BEGIN>,TrFade<300>,Stripes<3000,-3500,White,RandomPerLEDFlicker<Rgb<60,60,60>,Black>,BrownNoiseFlicker<White,Rgb<30,30,30>,200>,RandomPerLEDFlicker<Rgb<80,80,80>,Rgb<30,30,30>>>,TrFade<1100>>,EFFECT_IGNITION>,
    //Unstable ignition effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Bright humpflicker retraction effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,1500>,TrWipeInSparkTip<White,1000>>,
    //Spark tip ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "grey"}, 


    { "Magnetic;common", "tracks/venus.wav",
    StylePtr<Layers<
    AudioFlicker<StripesX<Sin<Int<4>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<-50>,Int<-100>>,StripesX<Sin<Int<3>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<25>,Int<80>>,Pulsing<RotateColorsX<Variation,Rgb16<0,65535,52226>>,RotateColorsX<Variation,Rgb16<0,33908,20693>>,3000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<0,63,200>>,RotateColorsX<Variation,Rgb<0,7,8>>>>,RotateColorsX<Variation,Rgb<0,39,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,36,30>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<25>,Int<75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<50,130,255>>>,RotateColorsX<Variation,Rgb<0,70,56>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,38,30>>,3000>>,AlphaL<StripesX<Sin<Int<8>,Int<3000>,Int<6000>>,Scale<TwistAngle<>,Int<60>,Int<140>>,StripesX<Sin<Int<6>,Int<1000>,Int<3000>>,Scale<TwistAngle<>,Int<-25>,Int<-80>>,Pulsing<Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb<50,130,255>>>,RotateColorsX<Variation,Rgb<0,12,14>>,4000>,Mix<Sin<Int<2>>,RotateColorsX<Variation,Rgb<50,130,255>>,Black>>,RotateColorsX<Variation,Rgb<0,39,40>>,Pulsing<RotateColorsX<Variation,Rgb<0,26,40>>,StripesX<Sin<Int<2>,Int<2000>,Int<4000>>,Sin<Int<2>,Int<-25>,Int<-75>>,Mix<Sin<Int<4>>,RotateColorsX<Variation,Cyan>,RotateColorsX<Variation,Rgb16<1899,49276,65535>>>,RotateColorsX<Variation,Rgb<0,30,96>>>,2000>,Pulsing<RotateColorsX<Variation,Rgb<0,40,128>>,RotateColorsX<Variation,Rgb<0,16,50>>,3000>>,Int<10000>>>,
    //Blue audioflicker lava lamp
    AlphaL<AudioFlickerL<AlphaL<Mix<Trigger<EFFECT_FORCE,Int<4000>,Int<3800>,Int<200>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Rgb16<33124,0,65535>>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb16<43654,0,65535>>,RotateColorsX<Variation,Rgb16<9500,0,14386>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Rgb16<0,65535,52226>>,RotateColorsX<Int<4000>,RotateColorsX<Variation,DeepSkyBlue>>>,RotateColorsX<Variation,Rgb16<43654,0,65535>>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-10000>,Int<36000>>,Int<-4000>>>>,SwingSpeed<450>>,
    //Unstable, audio responsive swing. Force effect triggers a brief "charge up" effect while swinging which works well with the overcharged smooth swing
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,White,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,Rgb16<11366,0,65535>>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<4000>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrFade<1040>,RotateColorsX<Variation,Rgb16<2521,681,18076>>,TrInstant,RotateColorsX<Variation,Rgb16<0,65535,52226>>,TrFade<550>>,EFFECT_IGNITION>,
    //Charge up ignition effect
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb16<40546,3350,65535>>>,TrFade<1000>>,EFFECT_RETRACTION>,
    //Purple retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrColorCycle<1040,5500,2000>,TrWipeInSparkTip<White,875>>,
    //Color cycle ignition, spark tip retraction
    //InOutTrL<TrWipeInSparkTip<White,1040>,TrWipeInSparkTip<White,875>>,
    //Alternate spark tip in ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "magnetic"}, 

    /*

    { "Masterless;common", "tracks/venus.wav",
    StylePtr<Layers<
    Stripes<15000,-300,RotateColorsX<Variation,Yellow>,Pulsing<RotateColorsX<Variation,Rgb<200,200,30>>,RotateColorsX<Variation,Rgb<180,180,0>>,800>,RotateColorsX<Variation,Rgb<180,180,0>>>,
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Rgb<180,180,0>>,RotateColorsX<Variation,Rgb<113,113,0>>>,TrDelay<30000>,RotateColorsX<Variation,Rgb<180,180,0>>,TrFade<800>>,EFFECT_FORCE>,
    AlphaL<RotateColorsX<Variation,Rgb<255,80,10>>,Scale<IsLessThan<SwingSpeed<300>,Int<13600>>,Scale<SwingSpeed<300>,Int<-19300>,Int<32768>>,Int<0>>>,
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Rgb<255,150,0>,Moccasin,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,Red,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    AlphaL<RotateColorsX<Variation,Rgb<230,180,80>>,Bump<Int<0>,Int<8000>>>,
    ResponsiveStabL<Red>,
    ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>>,
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    TransitionEffectL<TrConcat<TrInstant,AudioFlickerL<RotateColorsX<Variation,Rgb<230,180,80>>>,TrFade<1200>>,EFFECT_IGNITION>,
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTip<White,300,40>,TrWipeIn<1400>>,
    TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>>>(), "masterless"},


    { "Noble;common", "tracks/venus.wav",
    StylePtr<Layers<
    Stripes<5000,-75,RotateColorsX<Variation,Rgb<180,130,0>>,RotateColorsX<Variation,Rgb<200,120,0>>,RotateColorsX<Variation,Rgb<220,160,40>>,RotateColorsX<Variation,Rgb<170,95,0>>>,
    //Slightly different shades of yellow travel very slowly up the blade
    EffectSequence<EFFECT_FORCE,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<180,130,0>>,Black,300>,SwingSpeed<475>>,AlphaL<White,SwingSpeed<650>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,65535,28626>>,Black,300>,SwingSpeed<550>>>,
    //Force toggleable swing effects, triggering the force effect cycles through a bright unstable swing, an unstable swing, and a white swing
    //EffectSequence<EFFECT_FORCE,AlphaL<Mix<Sin<Int<1>>,ColorChange<TrInstant,Red>,Green,Blue,Red>,SwingSpeed<600>>,AlphaL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<95,0,210>>,Black>,White,RotateColorsX<Variation,Rgb<95,0,210>>,White>,SwingSpeed<600>>>,
    //Alternate swing effects, triggering the force effect toggles between unstable white ripple and color change swings
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,LemonChiffon>,Bump<Int<0>,Int<10000>>>,
    //Bright emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<White,40>,TrFade<1000>>,EFFECT_IGNITION>,
    //Bright HumpFlicker ignition effect
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,350>,TrWipeSparkTip<White,1250>>,
    //Spark tip out ignition and retraction
    //InOutTrL<TrWipeSparkTip<White,350>,TrWipeInSparkTip<White,1250>>,
    //Alternate spark tip out ignition and spark tip in retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "noble"}, 


    { "Ra;common", "tracks/venus.wav",
    StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Rgb16<65535,0,38402>>,RotateColorsX<Variation,Rgb<180,0,120>>>,
    //Magenta audioflicker
    AlphaL<AudioFlickerL<Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<230,0,35>>,Black>,Black,RotateColorsX<Variation,Rgb<230,0,35>>,Black>>,SwingSpeed<350>>,
    //Ripple audioflicker swing
    //AlphaL<AudioFlickerL<BrownNoiseFlicker<RotateColorsX<Variation,Rgb<230,0,35>>,Black,300>>,SwingSpeed<300>>,
    //Alternate unstable audioflicker swing
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<White>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    AlphaL<RotateColorsX<Variation,DeepPink>,SmoothStep<Scale<SlowNoise<Int<2500>>,Int<1000>,Int<3000>>,Int<-4000>>>,
    //Sparking emitter flare
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<White,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrColorCycle<3000,3000,0>,TrColorCycle<1250>>,
    //Color cycle ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "ra"}, 


    { "Seethe;common", "tracks/venus.wav",
    StylePtr<Layers<
    AudioFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<200,0,0>>>,
    //Red audioflicker
    TransitionEffectL<TrConcat<TrFade<200>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SwingSpeed<500>>,TrDelay<30000>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,SwingSpeed<500>>,TrFade<800>>,EFFECT_FORCE>,
    //Force effect, temporarily allows a swing effect where solid dark orange takes over the blade when swinging
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Red>,Black,300>,SwingSpeed<315>>,
    //Unstable swing
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<White,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    Mix<Sin<Int<8>>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Int<6000>>>,AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Int<22000>>>>,
    //Timed "breathing" emitter flare - NOTE: Due to the way Proffie works, this isn't always "lined up" and might be slightly ahead or slightly behind the hum's breathing. To fix you can turn the saber off and back on until it's lined up. The timing is right, but the code runs in the background even after turning the saber off so it doesn't always start "on time."
    //AlphaL<RotateColorsX<Variation,Rgb16<65535,11439,0>>,Bump<Int<0>,Scale<TwistAngle<>,Int<3000>,Int<20000>>>>,
    //Alternate twist responsive "breathing" emitter flare, twist the hilt in time with the breathing in a meditative way, or time it while going through different stances, etc.
    ResponsiveStabL<Orange>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,LocalizedClashL<White,80,30,EFFECT_BLAST>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,BlastL<White,200,200>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,240,80>,LemonChiffon,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Rgb<255,200,0>,DarkOrange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipe<2650>,TrWipeIn<1375>>,
    //Wipe out ignition, wipe in retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    >>(), "seethe"},


    { "Splinter;common", "tracks/venus.wav",
    StylePtr<Layers<
    Mix<SmoothStep<Scale<SwingSpeed<400>,Int<6000>,Int<24000>>,Int<10000>>,Stripes<5000,-1300,RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<60,17,0>>,RotateColorsX<Variation,Orange>,RotateColorsX<Variation,Rgb<128,34,0>>>,AudioFlicker<RotateColorsX<Variation,DarkOrange>,RotateColorsX<Variation,Rgb<168,54,0>>>>,
    //Split blade, orange audioflicker with a rolling pulse at the emitter, which takes over the blade more the harder you swing
    AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,DarkOrange>,Black,300>,SwingSpeed<600>>,
    //Unstable swing
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Azure>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<White,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,TransitionEffect<Azure,White,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,TrFade<400>>,TrConcat<TrInstant,TransitionEffect<White,Azure,TrInstant,TrFade<550>,EFFECT_LOCKUP_BEGIN>,TrFade<400>,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<65535,3131,0>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,17,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb16<65535,15911,1175>>,RotateColorsX<Variation,Rgb<60,17,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,34,0>>,RotateColorsX<Variation,Rgb<60,17,0>>>>,TrFade<1350>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup with splinter effect
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    ResponsiveStabL<Red>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Azure,White,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    TransitionEffectL<TrConcat<TrInstant,Stripes<3000,-3500,RotateColorsX<Variation,Rgb16<65535,58942,5401>>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<60,17,0>>,Black>,BrownNoiseFlicker<RotateColorsX<Variation,Rgb<255,178,110>>,RotateColorsX<Variation,Rgb<60,17,0>>,200>,RandomPerLEDFlicker<RotateColorsX<Variation,Rgb<128,34,0>>,RotateColorsX<Variation,Rgb<60,17,0>>>>,TrFade<2700>>,EFFECT_IGNITION>,
    //Unstable ignition with splinter effect
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<RotateColorsX<Variation,Rgb16<65535,58942,5401>>,40>,TrFade<1100>>,EFFECT_RETRACTION>,
    //Bright HumpFlicker retraction
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeInSparkTip<White,1100>>,
    //Spark tip ignition and retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,AlphaL<BrownNoiseFlickerL<White,Int<30>>,SmoothStep<Scale<SlowNoise<Int<2000>>,Int<1000>,Int<4000>>,Int<-4000>>>,TrDelay<1250>>,EFFECT_RETRACTION>
    //Cool down retraction
    >>(), "splinter"}, 



    { "Volatile;common", "tracks/venus.wav",
    StylePtr<Layers<
    Mix<Sin<Int<1>>,AudioFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb<0,0,128>>>,AudioFlicker<RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,128,0>>>>,
    //Rotates   ^ 1 time per minute between blue and green audioflicker
    EffectSequence<EFFECT_FORCE,AlphaL<Mix<Sin<Int<1>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,AlphaL<Mix<Sin<Int<2>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>>,
    //Force toggleable swing effect - switches betw^een unstable blue and green that cycle twice as fast as the base layer (so the blue and green don't always match up with the base layer, allowing for multiple mixes of blue/green) and unstable blue and green that match the base layer                                                                                                                                                                                                                             ^
    //AlphaL<Mix<Sin<Int<2>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,
    //AlphaL<Mix<Sin<Int<2>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,300>,SwingSpeed<400>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Black,300>,SwingSpeed<400>>>,SwingSpeed<400>>,
    //Alternate swing    ^ Rotates 2 times per minute between unstable ripple blue and green, so the blue and green don't always match up with the base layer, allowing for multiple mixes of blue/green
    //AlphaL<Mix<Sin<Int<1>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,Black>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>,RotateColorsX<Variation,Blue>,RotateColorsX<Variation,RotateColorsX<Variation,Rgb<0,0,45>>>>,Stripes<1000,-2000,RandomPerLEDFlicker<RotateColorsX<Variation,Green>,Black>,RotateColorsX<Variation,Rgb<0,45,0>>,RotateColorsX<Variation,Green>,RotateColorsX<Variation,Rgb<0,45,0>>>>,SwingSpeed<400>>,
    //AlphaL<Mix<Sin<Int<1>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Blue>,Black,300>,SwingSpeed<400>>,AlphaL<BrownNoiseFlicker<RotateColorsX<Variation,Green>,Black,300>,SwingSpeed<400>>>,SwingSpeed<400>>,
    //Alternate swing    ^ Rotates 1 time per minute between unstable ripple blue and green, matching the base layer
    LockupTrL<Layers<
        AlphaL<AudioFlickerL<Rgb<255,225,0>>,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,
        AlphaL<NavajoWhite,Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>,Int<10000>>>>,TrConcat<TrInstant,White,TrFade<400>>,TrConcat<TrInstant,AlphaL<White,Int<0>>,TrWaveX<TransitionEffect<NavajoWhite,Rgb<255,225,0>,TrInstant,TrFade<200>,EFFECT_LOCKUP_BEGIN>,Int<300>,Int<100>,Int<400>,Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>>>>,SaberBase::LOCKUP_NORMAL>,
    //Responsive lockup
    ResponsiveLightningBlockL<Strobe<White,AudioFlicker<White,Blue>,50,1>,TrConcat<TrInstant,AlphaL<White,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<White,Int<16000>>,30>,TrSmoothFade<600>>>,
    //Responsive lightning block
    ResponsiveStabL<Red,TrWipeIn<600>,TrWipe<600>>,
    //Responsive stab
    EffectSequence<EFFECT_BLAST,TransitionEffectL<TrConcat<TrInstant,AlphaL<White,BlastF<200,200>>,TrFade<300>>,EFFECT_BLAST>,ResponsiveBlastL<White,Int<400>,Scale<SwingSpeed<200>,Int<100>,Int<400>>,Int<400>>,ResponsiveBlastWaveL<White,Scale<SwingSpeed<400>,Int<500>,Int<200>>,Scale<SwingSpeed<400>,Int<100>,Int<400>>>,ResponsiveBlastFadeL<White,Scale<SwingSpeed<400>,Int<6000>,Int<12000>>,Scale<SwingSpeed<400>,Int<400>,Int<100>>>,ResponsiveBlastL<White,Scale<SwingSpeed<400>,Int<400>,Int<100>>,Scale<SwingSpeed<400>,Int<200>,Int<100>>,Scale<SwingSpeed<400>,Int<400>,Int<200>>>>,
    //Multi-blast, blaster reflect cycles through different responsive effects
    ResponsiveClashL<TransitionEffect<Rgb<255,225,0>,NavajoWhite,TrInstant,TrFade<100>,EFFECT_CLASH>,TrInstant,TrFade<400>,Scale<BladeAngle<0,16000>,Int<4000>,Int<26000>>,Int<6000>,Int<20000>>,
    //Responsive clash
    LockupTrL<AlphaL<BrownNoiseFlickerL<White,Int<300>>,SmoothStep<Int<30000>,Int<5000>>>,TrWipeIn<400>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    //Drag
    LockupTrL<AlphaL<Mix<TwistAngle<>,Red,Orange>,SmoothStep<Int<28000>,Int<5000>>>,TrWipeIn<600>,TrFade<300>,SaberBase::LOCKUP_MELT>,
    //Responsive melt
    EffectSequence<EFFECT_POWERSAVE,AlphaL<Black,Int<8192>>,AlphaL<Black,Int<16384>>,AlphaL<Black,Int<24576>>,AlphaL<Black,Int<0>>>,
    //Power save, if using fett263's prop file hold Aux and click PWR while ON (pointing up) to dim blade in 25% increments.
    InOutTrL<TrWipeSparkTip<White,300>,TrWipeIn<2000>>,
    //Spark tip ignition, wipe in retraction
    //TransitionEffectL<TrConcat<TrDelay<1500>,Black,TrFade<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_BOOT>,
    //TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<Int<0>,Int<6000>>>,TrFade<3000>>,EFFECT_NEWFONT>,
    //Optional/alternate passive battery monitor, on boot (1st line) or font change (2nd line) you will get a visual indicator at the emitter of your current battery level. This also works without a blade if you have a lit emitter or blade plug. Green is Full, Red is Low (the color will blend from Green to Red as the battery is depleted), the indicator will fade out after 3000 ms and not display again until powered down and back up or fonts change.
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrDelay<2000>,AlphaL<Mix<BatteryLevel,Red,Green>,Bump<BatteryLevel,Int<10000>>>,TrFade<1000>>,EFFECT_BATTERY_LEVEL>,
    //On demand battery level, if using fett263's prop file Hold AUX and click PWR while OFF, the battery level is represented by the location on the blade; tip = full, hilt = low and color; green = full, yellow = half, red = low
    TransitionEffectL<TrConcat<TrInstant,AlphaL<Mix<Trigger<EFFECT_PREON,Int<3000>,Int<3000>,Int<1000>>,BrownNoiseFlicker<Black,RotateColorsX<Variation,Blue>,100>,RandomPerLEDFlicker<RotateColorsX<Variation,Blue>,RotateColorsX<Variation,Rgb16<0,778,22863>>>,BrownNoiseFlicker<Mix<NoisySoundLevel,RotateColorsX<Variation,Blue>,RotateColorsX<Int<4000>,RotateColorsX<Variation,Cyan>>>,RotateColorsX<Variation,Green>,50>>,SmoothStep<Scale<NoisySoundLevel,Int<-2500>,Int<17500>>,Int<-4000>>>,TrDelay<6500>>,EFFECT_PREON>
    //Preon, reacts to sound level
    >>(), "volatile"}, 

    */

};
BladeConfig blades[] = {
 { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) },
};
#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif
