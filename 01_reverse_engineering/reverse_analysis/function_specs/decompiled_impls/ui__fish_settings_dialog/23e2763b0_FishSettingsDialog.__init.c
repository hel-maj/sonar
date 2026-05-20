/* ===== 23e2763b0 ui.fish_settings_dialog:c1129 ===== */
/* ghidra_name=FUN_23e2763b0 entry=23e2763b0 size=13019 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2763b0(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  undefined4 uVar15;
  longlong lVar16;
  longlong *plStack_b8;
  longlong *plStack_b0;
  longlong *plStack_a8;
  longlong *plStack_a0;
  longlong *plStack_98;
  longlong *plStack_90;
  longlong *plStack_88;
  undefined8 uStack_80;
  undefined8 uStack_78;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar8 = _DAT_23eeb0738;
  param_3 = (longlong *)*param_3;
  if (_DAT_23eeb0738 == (longlong *)0x0) {
LAB_23e2763f5:
    _DAT_23eeb0738 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb07b8,DAT_23eeb0770,0x68);
  }
  else {
    lVar6 = *_DAT_23eeb0738;
    if (1 < lVar6) {
      *_DAT_23eeb0738 = lVar6 + -1;
      goto LAB_23e2763f5;
    }
    if (_DAT_23eeb0738[2] != 0) {
      *_DAT_23eeb0738 = lVar6 + -1;
      if (lVar6 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23e2763f5;
    }
  }
  plVar3 = _DAT_23eeb0738;
  lVar6 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23eeb0738 + 9;
  lVar16 = *(longlong *)(lVar6 + 8);
  _DAT_23eeb0738[0xf] = lVar16;
  *(longlong **)(lVar6 + 8) = plVar8;
  if ((lVar16 != 0) &&
     (((*(char *)(lVar16 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar16 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar16 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar16 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar16 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar6 = FUN_23e8f97a0();
  if (lVar6 == 0) {
    FUN_23e915740(param_1,&uStack_68,DAT_23eeaf2c0);
    uStack_80 = uStack_68;
    uStack_78 = uStack_60;
    plVar7 = (longlong *)0x0;
    plVar8 = plStack_58;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x65;
    plVar7 = (longlong *)FUN_23e914090(param_1,lVar6,param_3);
    lVar6 = _DAT_23eeaf468;
    if (plVar7 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0x66;
      plVar8 = (longlong *)FUN_23e95a860(param_1,plVar7,DAT_23eeaf2d8,lVar6 + 0x18);
      if (plVar8 == (longlong *)0x0) {
        uStack_80 = *(undefined8 *)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        uVar15 = 0x66;
        uStack_78 = *(undefined8 *)(param_1 + 0x68);
        plStack_90 = (longlong *)0x0;
        plStack_88 = (longlong *)0x0;
        plStack_98 = (longlong *)0x0;
        plStack_a0 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
        goto LAB_23e277730;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar6 = _DAT_23eeaf470;
      *(undefined4 *)(plVar3 + 5) = 0x67;
      plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eeaf2c8,*(undefined8 *)(lVar6 + 0x18))
      ;
      if (plVar8 == (longlong *)0x0) {
        uStack_80 = *(undefined8 *)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = (longlong *)0x0;
        plVar10 = (longlong *)0x0;
        uVar15 = 0x67;
        uStack_78 = *(undefined8 *)(param_1 + 0x68);
        plStack_90 = (longlong *)0x0;
        plStack_88 = (longlong *)0x0;
        plStack_98 = (longlong *)0x0;
        plStack_a0 = (longlong *)0x0;
        plStack_b0 = (longlong *)0x0;
        plStack_b8 = (longlong *)0x0;
        plStack_a8 = (longlong *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = (longlong *)0x0;
        goto LAB_23e277730;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      lVar6 = FUN_23e8f9520();
      if (lVar6 == 0) {
        FUN_23e915740(param_1,&uStack_68,DAT_23eeaf2e8);
        uStack_80 = uStack_68;
        uStack_78 = uStack_60;
        plVar9 = (longlong *)0x0;
        plVar8 = plStack_58;
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0x6a;
        plVar9 = (longlong *)FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf478);
        lVar6 = _DAT_23eeaf480;
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0x6b;
          plVar8 = (longlong *)
                   FUN_23e915840(param_1,plVar9,DAT_23eeaf290,*(undefined8 *)(lVar6 + 0x18));
          if (plVar8 == (longlong *)0x0) {
            uStack_80 = *(undefined8 *)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar12 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar11 = (longlong *)0x0;
            uVar15 = 0x6b;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            plStack_90 = (longlong *)0x0;
            plStack_88 = (longlong *)0x0;
            plStack_98 = (longlong *)0x0;
            plStack_a0 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = (longlong *)0x0;
            goto LAB_23e277730;
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          lVar6 = _DAT_23eeaf488;
          *(undefined4 *)(plVar3 + 5) = 0x6c;
          plVar8 = (longlong *)
                   FUN_23e915840(param_1,plVar9,DAT_23eeaf350,*(undefined8 *)(lVar6 + 0x18));
          if (plVar8 == (longlong *)0x0) {
            uStack_80 = *(undefined8 *)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar12 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar11 = (longlong *)0x0;
            uVar15 = 0x6c;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            plStack_90 = (longlong *)0x0;
            plStack_88 = (longlong *)0x0;
            plStack_98 = (longlong *)0x0;
            plStack_a0 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = (longlong *)0x0;
            goto LAB_23e277730;
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          *(undefined4 *)(plVar3 + 5) = 0x6d;
          plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eeaf388,plVar9);
          if (plVar8 == (longlong *)0x0) {
            uStack_80 = *(undefined8 *)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            plVar12 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar11 = (longlong *)0x0;
            uVar15 = 0x6d;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            plStack_90 = (longlong *)0x0;
            plStack_88 = (longlong *)0x0;
            plStack_98 = (longlong *)0x0;
            plStack_a0 = (longlong *)0x0;
            plStack_b0 = (longlong *)0x0;
            plStack_b8 = (longlong *)0x0;
            plStack_a8 = (longlong *)0x0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = (longlong *)0x0;
            goto LAB_23e277730;
          }
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          lVar6 = FUN_23e8f9520();
          if (lVar6 == 0) {
            FUN_23e915740(param_1,&uStack_68,DAT_23eeaf2e8);
            uStack_80 = uStack_68;
            uStack_78 = uStack_60;
            plVar10 = (longlong *)0x0;
            plVar8 = plStack_58;
          }
          else {
            *(undefined4 *)(plVar3 + 5) = 0x70;
            plVar10 = (longlong *)FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf490);
            lVar6 = _DAT_23eeaf498;
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0x71;
              plVar8 = (longlong *)
                       FUN_23e915840(param_1,plVar10,DAT_23eeaf290,*(undefined8 *)(lVar6 + 0x18));
              if (plVar8 == (longlong *)0x0) {
                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                plVar12 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar15 = 0x71;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                plStack_90 = (longlong *)0x0;
                plStack_88 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                plStack_a0 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_a8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
                goto LAB_23e277730;
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              lVar6 = DAT_23eeaf398;
              *(undefined4 *)(plVar3 + 5) = 0x72;
              plVar8 = (longlong *)
                       FUN_23e915840(param_1,plVar10,DAT_23eeaf390,*(undefined8 *)(lVar6 + 0x18));
              if (plVar8 == (longlong *)0x0) {
                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                plVar12 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar15 = 0x72;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                plStack_90 = (longlong *)0x0;
                plStack_88 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                plStack_a0 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_a8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
                goto LAB_23e277730;
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              *(undefined4 *)(plVar3 + 5) = 0x73;
              plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eeaf388,plVar10);
              if (plVar8 == (longlong *)0x0) {
                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                plVar12 = (longlong *)0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar15 = 0x73;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                plStack_90 = (longlong *)0x0;
                plStack_88 = (longlong *)0x0;
                plStack_98 = (longlong *)0x0;
                plStack_a0 = (longlong *)0x0;
                plStack_b0 = (longlong *)0x0;
                plStack_b8 = (longlong *)0x0;
                plStack_a8 = (longlong *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar11 = (longlong *)0x0;
                goto LAB_23e277730;
              }
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              lVar6 = FUN_23e8f9650();
              if (lVar6 == 0) {
                FUN_23e915740(param_1,&uStack_68,DAT_23eeaf3a8);
                uStack_80 = uStack_68;
                uStack_78 = uStack_60;
                plVar11 = (longlong *)0x0;
                plVar8 = plStack_58;
              }
              else {
                *(undefined4 *)(plVar3 + 5) = 0x76;
                plVar11 = (longlong *)FUN_23e91a870(param_1,lVar6);
                if (plVar11 != (longlong *)0x0) {
                  lVar6 = FUN_23e8f9280();
                  if (lVar6 == 0) {
                    FUN_23e915740(param_1,&uStack_68,DAT_23eeaf4a0);
                    uStack_80 = uStack_68;
                    uStack_78 = uStack_60;
                    plStack_a8 = (longlong *)0x0;
                    plVar8 = plStack_58;
                  }
                  else {
                    *(undefined4 *)(plVar3 + 5) = 0x78;
                    plStack_a8 = (longlong *)FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf4a8);
                    if (plStack_a8 != (longlong *)0x0) {
                      plVar8 = (longlong *)FUN_23e8bc2f0(plStack_a8,_DAT_23eeaf4b0);
                      if (plVar8 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2784b4:
                        plVar12 = (longlong *)0x0;
                        plStack_90 = (longlong *)0x0;
                        uVar15 = 0x79;
                        plStack_88 = (longlong *)0x0;
                        plStack_98 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
                        plStack_b0 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        goto LAB_23e277730;
                      }
                      plVar12 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeaf4b8);
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar12 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        plVar12 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar15 = 0x79;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        plStack_90 = (longlong *)0x0;
                        plStack_88 = (longlong *)0x0;
                        plStack_98 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
                        plStack_b0 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plStack_b8 = (longlong *)0x0;
                        goto LAB_23e277730;
                      }
                      plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeaf4c0);
                      if (plVar8 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        lVar6 = *plVar12;
                        *plVar12 = lVar6 + -1;
                        if (lVar6 + -1 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                        }
                        goto LAB_23e2784b4;
                      }
                      *(undefined4 *)(plVar3 + 5) = 0x79;
                      plVar13 = (longlong *)FUN_23e914090(param_1,plVar12,plVar8);
                      lVar6 = *plVar12;
                      *plVar12 = lVar6 + -1;
                      if (lVar6 + -1 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      if (plVar13 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        plVar12 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar15 = 0x79;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        plStack_90 = (longlong *)0x0;
                        plStack_88 = (longlong *)0x0;
                        plStack_98 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plStack_b0 = (longlong *)0x0;
                        goto LAB_23e277730;
                      }
                      lVar6 = *plVar13;
                      *plVar13 = lVar6 + -1;
                      if (lVar6 + -1 == 0) {
                        (**(code **)(plVar13[1] + 0x30))();
                      }
                      *(undefined4 *)(plVar3 + 5) = 0x7a;
                      plVar8 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23eeaf388,plStack_a8);
                      if (plVar8 == (longlong *)0x0) {
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        plStack_90 = (longlong *)0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar15 = 0x7a;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        plStack_88 = (longlong *)0x0;
                        plStack_98 = (longlong *)0x0;
                        plStack_a0 = (longlong *)0x0;
                        plStack_b0 = (longlong *)0x0;
                        plStack_b8 = (longlong *)0x0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar12 = (longlong *)0x0;
                        goto LAB_23e277730;
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      lVar6 = FUN_23e8f9280();
                      if (lVar6 == 0) {
                        FUN_23e915740(param_1,&uStack_68,DAT_23eeaf4a0);
                        uStack_80 = uStack_68;
                        uStack_78 = uStack_60;
                        plVar12 = (longlong *)0x0;
                        plVar8 = plStack_58;
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x7c;
                        plVar12 = (longlong *)FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf4c8);
                        if (plVar12 != (longlong *)0x0) {
                          plVar8 = (longlong *)FUN_23e8bc2f0(plVar12,_DAT_23eeaf4b0);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e278751:
                            plStack_b8 = (longlong *)0x0;
                            plStack_90 = (longlong *)0x0;
                            uVar15 = 0x7d;
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          plVar13 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeaf4b8);
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          if (plVar13 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x7d;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b0 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeaf4d0);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            lVar6 = *plVar13;
                            *plVar13 = lVar6 + -1;
                            if (lVar6 + -1 == 0) {
                              (**(code **)(plVar13[1] + 0x30))(plVar13);
                            }
                            goto LAB_23e278751;
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x7d;
                          plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar8);
                          lVar6 = *plVar13;
                          *plVar13 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar13[1] + 0x30))(plVar13);
                          }
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          if (plVar14 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x7d;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            plStack_b8 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_a0 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = *plVar14;
                          *plVar14 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar14[1] + 0x30))();
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x7e;
                          plVar8 = (longlong *)FUN_23e915840(param_1,plVar11,DAT_23eeaf388,plVar12);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x7e;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b8 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x80;
                          plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar11,_DAT_23eeaf4d8);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x80;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b8 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x81;
                          plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eeaf400,plVar11);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x81;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b8 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))();
                          }
                          lVar6 = *(longlong *)(DAT_23eeaf268 + 0x20);
                          if (*(char *)(lVar6 + 10) == '\0') {
                            plVar8 = (longlong *)FUN_23a37a020(DAT_23eeaf268,_DAT_23eeaf4e0);
                            if (plVar8 == (longlong *)0x0) goto LAB_23e27866d;
                            lVar6 = *plVar8;
LAB_23e278664:
                            if (lVar6 == 0) goto LAB_23e27866d;
                          }
                          else {
                            iVar5 = *(int *)(lVar6 + 0xc);
                            if (*(int *)(lVar6 + 0xc) == 0) {
                              *(int *)(lVar6 + 0xc) = DAT_23ec14f00;
                              iVar5 = DAT_23ec14f00;
                              DAT_23ec14f00 = DAT_23ec14f00 + 1;
                            }
                            if (_DAT_23ec14eec != iVar5) {
                              _DAT_23ec14eec = iVar5;
                              _DAT_23eeb0720 =
                                   FUN_23e8cbd60(lVar6,_DAT_23eeaf4e0,
                                                 *(undefined8 *)(_DAT_23eeaf4e0 + 0x18));
                            }
                            if (-1 < _DAT_23eeb0720) {
                              lVar16 = lVar6 + 0x20 + (1L << (*(byte *)(lVar6 + 9) & 0x3f));
                              if (*(longlong *)(lVar16 + 8 + _DAT_23eeb0720 * 0x10) != 0)
                              goto LAB_23e276b3b;
                              _DAT_23eeb0720 =
                                   FUN_23e8cbd60(lVar6,_DAT_23eeaf4e0,
                                                 *(undefined8 *)(_DAT_23eeaf4e0 + 0x18));
                              if (-1 < _DAT_23eeb0720) {
                                lVar6 = *(longlong *)(lVar16 + 8 + _DAT_23eeb0720 * 0x10);
                                goto LAB_23e278664;
                              }
                            }
LAB_23e27866d:
                            plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaf4e0);
                            if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
                              FUN_23e915740(param_1,&uStack_68,_DAT_23eeaf4e0);
                              uVar15 = 0x84;
                              plStack_90 = (longlong *)0x0;
                              plStack_88 = (longlong *)0x0;
                              uStack_80 = uStack_68;
                              plStack_98 = (longlong *)0x0;
                              uStack_78 = uStack_60;
                              plStack_a0 = (longlong *)0x0;
                              plStack_b0 = (longlong *)0x0;
                              plStack_b8 = (longlong *)0x0;
                              plVar8 = plStack_58;
                              goto LAB_23e277730;
                            }
                          }
LAB_23e276b3b:
                          *(undefined4 *)(plVar3 + 5) = 0x84;
                          plStack_b8 = (longlong *)FUN_23e91a870(param_1);
                          if (plStack_b8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x84;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            plStack_b0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            goto LAB_23e277730;
                          }
                          *(undefined4 *)(plVar3 + 5) = 0x85;
                          plVar8 = (longlong *)FUN_23e915840(param_1,plStack_b8,_DAT_23eeaf4e8);
                          if (plVar8 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x85;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b0 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = *plVar8;
                          *plVar8 = lVar6 + -1;
                          if (lVar6 + -1 == 0) {
                            (**(code **)(plVar8[1] + 0x30))(plVar8);
                          }
                          plVar13 = (longlong *)FUN_23e8bc2f0(plStack_b8,DAT_23eeaf2a0);
                          if (plVar13 == (longlong *)0x0) {
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            plStack_90 = (longlong *)0x0;
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uVar15 = 0x86;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            plStack_88 = (longlong *)0x0;
                            plStack_98 = (longlong *)0x0;
                            plStack_a0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                            plStack_b0 = (longlong *)0x0;
                            goto LAB_23e277730;
                          }
                          lVar6 = FUN_23e8f98d0();
                          if (lVar6 == 0) {
                            FUN_23e915740(param_1,&uStack_68,DAT_23eeaf2a8);
                            lVar6 = *plVar13 + -1;
                            *plVar13 = lVar6;
                            uStack_80 = uStack_68;
                            uStack_78 = uStack_60;
                            plVar8 = plStack_58;
joined_r0x00023e278fbc:
                            if (lVar6 == 0) {
                              FUN_23a334bc0(plVar13);
                            }
                          }
                          else {
                            plVar8 = (longlong *)FUN_23e8bc2f0(lVar6,DAT_23eeaf2b0);
                            if (plVar8 == (longlong *)0x0) {
                              uStack_80 = *(undefined8 *)(param_1 + 0x60);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              lVar6 = *plVar13 + -1;
                              *plVar13 = lVar6;
                              goto joined_r0x00023e278fbc;
                            }
                            plVar14 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeaf4f0);
                            lVar6 = *plVar8;
                            *plVar8 = lVar6 + -1;
                            if (lVar6 + -1 == 0) {
                              (**(code **)(plVar8[1] + 0x30))(plVar8);
                            }
                            if (plVar14 == (longlong *)0x0) {
                              uStack_80 = *(undefined8 *)(param_1 + 0x60);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              lVar6 = *plVar13;
                              *plVar13 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              plStack_90 = (longlong *)0x0;
                              uVar15 = 0x86;
                              plStack_88 = (longlong *)0x0;
                              plStack_a0 = (longlong *)0x0;
                              plStack_b0 = (longlong *)0x0;
                              plStack_98 = (longlong *)0x0;
                              goto LAB_23e277730;
                            }
                            *(undefined4 *)(plVar3 + 5) = 0x86;
                            plVar8 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
                            lVar6 = *plVar13;
                            *plVar13 = lVar6 + -1;
                            if (lVar6 + -1 == 0) {
                              (**(code **)(plVar13[1] + 0x30))(plVar13);
                            }
                            lVar6 = *plVar14;
                            *plVar14 = lVar6 + -1;
                            if (lVar6 + -1 == 0) {
                              (**(code **)(plVar14[1] + 0x30))(plVar14);
                            }
                            if (plVar8 != (longlong *)0x0) {
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))();
                              }
                              lVar6 = *(longlong *)(DAT_23eeaf268 + 0x20);
                              if (*(char *)(lVar6 + 10) == '\0') {
                                plVar8 = (longlong *)FUN_23a37a020(DAT_23eeaf268,_DAT_23eeaf4f8);
                                if (plVar8 == (longlong *)0x0) goto LAB_23e2789dd;
                                lVar6 = *plVar8;
LAB_23e2789d4:
                                if (lVar6 == 0) goto LAB_23e2789dd;
                              }
                              else {
                                iVar5 = *(int *)(lVar6 + 0xc);
                                if (*(int *)(lVar6 + 0xc) == 0) {
                                  *(int *)(lVar6 + 0xc) = DAT_23ec14f00;
                                  iVar5 = DAT_23ec14f00;
                                  DAT_23ec14f00 = DAT_23ec14f00 + 1;
                                }
                                if (_DAT_23ec14ef0 != iVar5) {
                                  _DAT_23ec14ef0 = iVar5;
                                  _DAT_23eeb0728 =
                                       FUN_23e8cbd60(lVar6,_DAT_23eeaf4f8,
                                                     *(undefined8 *)(_DAT_23eeaf4f8 + 0x18));
                                }
                                if (-1 < _DAT_23eeb0728) {
                                  lVar16 = lVar6 + 0x20 + (1L << (*(byte *)(lVar6 + 9) & 0x3f));
                                  if (*(longlong *)(lVar16 + 8 + _DAT_23eeb0728 * 0x10) != 0)
                                  goto LAB_23e276d68;
                                  _DAT_23eeb0728 =
                                       FUN_23e8cbd60(lVar6,_DAT_23eeaf4f8,
                                                     *(undefined8 *)(_DAT_23eeaf4f8 + 0x18));
                                  if (-1 < _DAT_23eeb0728) {
                                    lVar6 = *(longlong *)(lVar16 + 8 + _DAT_23eeb0728 * 0x10);
                                    goto LAB_23e2789d4;
                                  }
                                }
LAB_23e2789dd:
                                plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaf4f8);
                                if ((plVar8 == (longlong *)0x0) || (*plVar8 == 0)) {
                                  FUN_23e915740(param_1,&uStack_68);
                                  plStack_90 = (longlong *)0x0;
                                  uVar15 = 0x88;
                                  uStack_80 = uStack_68;
                                  plStack_88 = (longlong *)0x0;
                                  uStack_78 = uStack_60;
                                  plStack_98 = (longlong *)0x0;
                                  plStack_a0 = (longlong *)0x0;
                                  plStack_b0 = (longlong *)0x0;
                                  plVar8 = plStack_58;
                                  goto LAB_23e277730;
                                }
                              }
LAB_23e276d68:
                              *(undefined4 *)(plVar3 + 5) = 0x88;
                              plStack_b0 = (longlong *)FUN_23e91a870(param_1);
                              if (plStack_b0 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar15 = 0x88;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                plStack_a0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *(longlong *)(DAT_23eeaf268 + 0x20);
                              if (*(char *)(lVar6 + 10) == '\0') {
                                plVar8 = (longlong *)FUN_23a37a020(DAT_23eeaf268,_DAT_23eeaf500);
                                if (plVar8 == (longlong *)0x0) goto LAB_23e278c76;
                                lVar16 = *plVar8;
LAB_23e278c6d:
                                if (lVar16 == 0) goto LAB_23e278c76;
                              }
                              else {
                                iVar5 = *(int *)(lVar6 + 0xc);
                                if (*(int *)(lVar6 + 0xc) == 0) {
                                  *(int *)(lVar6 + 0xc) = DAT_23ec14f00;
                                  iVar5 = DAT_23ec14f00;
                                  DAT_23ec14f00 = DAT_23ec14f00 + 1;
                                }
                                if (_DAT_23ec14ef4 != iVar5) {
                                  _DAT_23ec14ef4 = iVar5;
                                  _DAT_23eeb0730 =
                                       FUN_23e8cbd60(lVar6,_DAT_23eeaf500,
                                                     *(undefined8 *)(_DAT_23eeaf500 + 0x18));
                                }
                                if (-1 < _DAT_23eeb0730) {
                                  lVar1 = lVar6 + 0x20 + (1L << (*(byte *)(lVar6 + 9) & 0x3f));
                                  lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0730 * 0x10);
                                  if (lVar16 != 0) goto LAB_23e276df9;
                                  _DAT_23eeb0730 =
                                       FUN_23e8cbd60(lVar6,_DAT_23eeaf500,
                                                     *(undefined8 *)(_DAT_23eeaf500 + 0x18));
                                  if (-1 < _DAT_23eeb0730) {
                                    lVar16 = *(longlong *)(lVar1 + 8 + _DAT_23eeb0730 * 0x10);
                                    goto LAB_23e278c6d;
                                  }
                                }
LAB_23e278c76:
                                plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeaf500);
                                if ((plVar8 == (longlong *)0x0) || (lVar16 = *plVar8, lVar16 == 0))
                                {
                                  FUN_23e915740(param_1,&uStack_68,_DAT_23eeaf500);
                                  plStack_90 = (longlong *)0x0;
                                  uVar15 = 0x89;
                                  uStack_80 = uStack_68;
                                  plStack_88 = (longlong *)0x0;
                                  uStack_78 = uStack_60;
                                  plStack_98 = (longlong *)0x0;
                                  plStack_a0 = (longlong *)0x0;
                                  plVar8 = plStack_58;
                                  goto LAB_23e277730;
                                }
                              }
LAB_23e276df9:
                              *(undefined4 *)(plVar3 + 5) = 0x89;
                              plStack_a0 = (longlong *)FUN_23e914090(param_1,lVar16,plStack_b0);
                              lVar6 = _DAT_23eeaf470;
                              if (plStack_a0 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                uVar15 = 0x89;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e277730;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x8a;
                              plVar8 = (longlong *)
                                       FUN_23e915840(param_1,plStack_a0,DAT_23eeaf2c8,
                                                     *(undefined8 *)(lVar6 + 0x18));
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar15 = 0x8a;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_90 = (longlong *)0x0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              lVar6 = _DAT_23eeaf508;
                              *(undefined4 *)(plVar3 + 5) = 0x8b;
                              plVar8 = (longlong *)
                                       FUN_23e95a860(param_1,plStack_a0,DAT_23eeaf2d8,lVar6 + 0x18);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar15 = 0x8b;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_90 = (longlong *)0x0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x8e;
                              plVar8 = (longlong *)
                                       FUN_23e915840(param_1,param_3,_DAT_23eeaf510,plStack_a0);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar15 = 0x8e;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_90 = (longlong *)0x0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))();
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x90;
                              plVar8 = (longlong *)
                                       FUN_23e915840(param_1,plStack_b8,_DAT_23eeaf518,plStack_b0);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar15 = 0x90;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_90 = (longlong *)0x0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))(plVar8);
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x91;
                              plVar8 = (longlong *)FUN_23e915840(param_1,plVar7,DAT_23eeaf388);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                uVar15 = 0x91;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_90 = (longlong *)0x0;
                                plStack_88 = (longlong *)0x0;
                                plStack_98 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                (**(code **)(plVar8[1] + 0x30))();
                              }
                              lVar6 = FUN_23e8f9650();
                              if (lVar6 == 0) {
                                FUN_23e915740(param_1,&uStack_68,DAT_23eeaf3a8);
                                plStack_90 = (longlong *)0x0;
                                uVar15 = 0x94;
                                uStack_80 = uStack_68;
                                plStack_88 = (longlong *)0x0;
                                uStack_78 = uStack_60;
                                plStack_98 = (longlong *)0x0;
                                plVar8 = plStack_58;
                                goto LAB_23e277730;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x94;
                              plStack_98 = (longlong *)FUN_23e91a870(param_1,lVar6);
                              if (plStack_98 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                uVar15 = 0x94;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                plStack_88 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e277730;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x95;
                              plVar8 = (longlong *)FUN_23e91bfe0(param_1,plStack_98,_DAT_23eeaf4d8);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                uVar15 = 0x95;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_88 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                FUN_23a334bc0(plVar8);
                              }
                              lVar6 = FUN_23e8f9280();
                              if (lVar6 == 0) {
                                FUN_23e915740(param_1,&uStack_68);
                                plStack_90 = (longlong *)0x0;
                                uVar15 = 0x97;
                                uStack_80 = uStack_68;
                                uStack_78 = uStack_60;
                                plStack_88 = (longlong *)0x0;
                                plVar8 = plStack_58;
                                goto LAB_23e277730;
                              }
                              *(undefined4 *)(plVar3 + 5) = 0x97;
                              plStack_88 = (longlong *)FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf520);
                              if (plStack_88 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                plStack_90 = (longlong *)0x0;
                                uVar15 = 0x97;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e277730;
                              }
                              plVar8 = (longlong *)FUN_23e8bc2f0(plStack_88);
                              if (plVar8 == (longlong *)0x0) {
                                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                plVar8 = *(longlong **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                uVar15 = 0x98;
                                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                plStack_90 = (longlong *)0x0;
                                goto LAB_23e277730;
                              }
                              plVar13 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeaf4b8);
                              lVar6 = *plVar8;
                              *plVar8 = lVar6 + -1;
                              if (lVar6 + -1 == 0) {
                                FUN_23a334bc0(plVar8);
                              }
                              if (plVar13 != (longlong *)0x0) {
                                plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeaf528);
                                if (plVar8 == (longlong *)0x0) {
                                  uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                  uVar15 = 0x98;
                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *plVar13 = *plVar13 + -1;
                                  lVar6 = *plVar13;
                                  plStack_90 = (longlong *)0x0;
joined_r0x00023e279440:
                                  if (lVar6 == 0) {
                                    FUN_23a334bc0(plVar13);
                                  }
                                  goto LAB_23e277730;
                                }
                                *(undefined4 *)(plVar3 + 5) = 0x98;
                                plVar14 = (longlong *)FUN_23e914090(param_1,plVar13,plVar8);
                                *plVar13 = *plVar13 + -1;
                                if (*plVar13 == 0) {
                                  FUN_23a334bc0(plVar13);
                                }
                                lVar6 = *plVar8;
                                *plVar8 = lVar6 + -1;
                                if (lVar6 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                if (plVar14 != (longlong *)0x0) {
                                  *plVar14 = *plVar14 + -1;
                                  if (*plVar14 == 0) {
                                    FUN_23a334bc0(plVar14);
                                  }
                                  lVar6 = _DAT_23eeaf538;
                                  *(undefined4 *)(plVar3 + 5) = 0x99;
                                  plVar8 = (longlong *)
                                           FUN_23e915840(param_1,plStack_88,_DAT_23eeaf530,
                                                         *(undefined8 *)(lVar6 + 0x18));
                                  if (plVar8 == (longlong *)0x0) {
                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    uVar15 = 0x99;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_90 = (longlong *)0x0;
                                    goto LAB_23e277730;
                                  }
                                  lVar6 = *plVar8;
                                  *plVar8 = lVar6 + -1;
                                  if (lVar6 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  *(undefined4 *)(plVar3 + 5) = 0x9a;
                                  plVar8 = (longlong *)
                                           FUN_23e915840(param_1,plStack_98,DAT_23eeaf388,plStack_88
                                                        );
                                  if (plVar8 == (longlong *)0x0) {
                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    uVar15 = 0x9a;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    plStack_90 = (longlong *)0x0;
                                    goto LAB_23e277730;
                                  }
                                  lVar6 = *plVar8;
                                  *plVar8 = lVar6 + -1;
                                  if (lVar6 + -1 == 0) {
                                    FUN_23a334bc0(plVar8);
                                  }
                                  lVar6 = FUN_23e8f9280();
                                  if (lVar6 == 0) {
                                    FUN_23e915740(param_1,&uStack_68,DAT_23eeaf4a0);
                                    uVar15 = 0x9c;
                                    uStack_80 = uStack_68;
                                    uStack_78 = uStack_60;
                                    plStack_90 = (longlong *)0x0;
                                    plVar8 = plStack_58;
                                    goto LAB_23e277730;
                                  }
                                  *(undefined4 *)(plVar3 + 5) = 0x9c;
                                  plStack_90 = (longlong *)
                                               FUN_23e94bb80(param_1,lVar6,_DAT_23eeaf540);
                                  lVar6 = _DAT_23eeaf548;
                                  if (plStack_90 == (longlong *)0x0) {
                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    uVar15 = 0x9c;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    goto LAB_23e277730;
                                  }
                                  *(undefined4 *)(plVar3 + 5) = 0x9d;
                                  plVar8 = (longlong *)
                                           FUN_23e915840(param_1,plStack_90,DAT_23eeaf290,
                                                         *(undefined8 *)(lVar6 + 0x18));
                                  if (plVar8 == (longlong *)0x0) {
                                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    uVar15 = 0x9d;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    goto LAB_23e277730;
                                  }
                                  *plVar8 = *plVar8 + -1;
                                  if (*plVar8 == 0) {
                                    FUN_23a334bc0(plVar8);
                                  }
                                  plVar8 = (longlong *)FUN_23e8bc2f0(plStack_90,_DAT_23eeaf4b0);
                                  if (plVar8 != (longlong *)0x0) {
                                    plVar13 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23eeaf4b8);
                                    *plVar8 = *plVar8 + -1;
                                    if (*plVar8 == 0) {
                                      FUN_23a334bc0(plVar8);
                                    }
                                    if (plVar13 != (longlong *)0x0) {
                                      plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eeaf550);
                                      if (plVar8 == (longlong *)0x0) {
                                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        uVar15 = 0x9e;
                                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        *plVar13 = *plVar13 + -1;
                                        lVar6 = *plVar13;
                                        goto joined_r0x00023e279440;
                                      }
                                      *(undefined4 *)(plVar3 + 5) = 0x9e;
                                      plVar14 = (longlong *)FUN_23e914090(param_1,plVar13);
                                      *plVar13 = *plVar13 + -1;
                                      if (*plVar13 == 0) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      if (plVar14 != (longlong *)0x0) {
                                        *plVar14 = *plVar14 + -1;
                                        if (*plVar14 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                        lVar6 = _DAT_23eeaf538;
                                        *(undefined4 *)(plVar3 + 5) = 0x9f;
                                        plVar8 = (longlong *)
                                                 FUN_23e915840(param_1,plStack_90,_DAT_23eeaf530,
                                                               *(undefined8 *)(lVar6 + 0x18));
                                        if (plVar8 == (longlong *)0x0) {
                                          uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                          plVar8 = *(longlong **)(param_1 + 0x70);
                                          uVar15 = 0x9f;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          *plVar8 = *plVar8 + -1;
                                          if (*plVar8 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          *(undefined4 *)(plVar3 + 5) = 0xa0;
                                          plVar8 = (longlong *)
                                                   FUN_23e915840(param_1,plStack_98,DAT_23eeaf388,
                                                                 plStack_90);
                                          if (plVar8 == (longlong *)0x0) {
                                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            uVar15 = 0xa0;
                                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else {
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              FUN_23a334bc0(plVar8);
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0xa2;
                                            plVar8 = (longlong *)
                                                     FUN_23e915840(param_1,plVar7,DAT_23eeaf400,
                                                                   plStack_98);
                                            if (plVar8 != (longlong *)0x0) {
                                              *plVar8 = *plVar8 + -1;
                                              if (*plVar8 == 0) {
                                                FUN_23a334bc0(plVar8);
                                              }
                                              FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                                              pcVar4 = _Py_NoneStruct_exref;
                                              *(longlong *)_Py_NoneStruct_exref =
                                                   *(longlong *)_Py_NoneStruct_exref + 1;
                                              *plVar7 = *plVar7 + -1;
                                              if (*plVar7 == 0) {
                                                FUN_23a334bc0(plVar7);
                                              }
                                              *plVar9 = *plVar9 + -1;
                                              if (*plVar9 == 0) {
                                                FUN_23a334bc0(plVar9);
                                              }
                                              *plVar10 = *plVar10 + -1;
                                              if (*plVar10 == 0) {
                                                FUN_23a334bc0(plVar10);
                                              }
                                              *plVar11 = *plVar11 + -1;
                                              if (*plVar11 == 0) {
                                                FUN_23a334bc0(plVar11);
                                              }
                                              lVar6 = *plStack_a8;
                                              *plStack_a8 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_a8);
                                              }
                                              *plVar12 = *plVar12 + -1;
                                              if (*plVar12 == 0) {
                                                FUN_23a334bc0(plVar12);
                                              }
                                              lVar6 = *plStack_b8;
                                              *plStack_b8 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_b8);
                                              }
                                              lVar6 = *plStack_b0;
                                              *plStack_b0 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_b0);
                                              }
                                              lVar6 = *plStack_a0;
                                              *plStack_a0 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_a0);
                                              }
                                              lVar6 = *plStack_98;
                                              *plStack_98 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_98);
                                              }
                                              lVar6 = *plStack_88;
                                              *plStack_88 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_88);
                                              }
                                              lVar6 = *plStack_90;
                                              *plStack_90 = lVar6 + -1;
                                              if (lVar6 + -1 == 0) {
                                                FUN_23a334bc0(plStack_90);
                                              }
                                              lVar6 = *param_3;
                                              *param_3 = lVar6 + -1;
                                              if (lVar6 + -1 != 0) {
                                                return pcVar4;
                                              }
                                              FUN_23a334bc0(param_3);
                                              return pcVar4;
                                            }
                                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                            plVar8 = *(longlong **)(param_1 + 0x70);
                                            uVar15 = 0xa2;
                                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                          }
                                        }
                                        goto LAB_23e277730;
                                      }
                                    }
                                  }
                                  uStack_80 = *(undefined8 *)(param_1 + 0x60);
                                  plVar8 = *(longlong **)(param_1 + 0x70);
                                  uVar15 = 0x9e;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  uStack_78 = *(undefined8 *)(param_1 + 0x68);
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e277730;
                                }
                              }
                              uStack_80 = *(undefined8 *)(param_1 + 0x60);
                              plVar8 = *(longlong **)(param_1 + 0x70);
                              uVar15 = 0x98;
                              uStack_78 = *(undefined8 *)(param_1 + 0x68);
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              plStack_90 = (longlong *)0x0;
                              goto LAB_23e277730;
                            }
                            uStack_80 = *(undefined8 *)(param_1 + 0x60);
                            plVar8 = *(longlong **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            uStack_78 = *(undefined8 *)(param_1 + 0x68);
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          plStack_a0 = (longlong *)0x0;
                          plStack_90 = (longlong *)0x0;
                          uVar15 = 0x86;
                          plStack_88 = (longlong *)0x0;
                          plStack_98 = (longlong *)0x0;
                          plStack_b0 = (longlong *)0x0;
                          goto LAB_23e277730;
                        }
                        uStack_80 = *(undefined8 *)(param_1 + 0x60);
                        plVar8 = *(longlong **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uStack_78 = *(undefined8 *)(param_1 + 0x68);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      plStack_90 = (longlong *)0x0;
                      uVar15 = 0x7c;
                      plStack_88 = (longlong *)0x0;
                      plStack_98 = (longlong *)0x0;
                      plStack_a0 = (longlong *)0x0;
                      plStack_b0 = (longlong *)0x0;
                      plStack_b8 = (longlong *)0x0;
                      goto LAB_23e277730;
                    }
                    uStack_80 = *(undefined8 *)(param_1 + 0x60);
                    plVar8 = *(longlong **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_78 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  }
                  plStack_90 = (longlong *)0x0;
                  plVar12 = (longlong *)0x0;
                  uVar15 = 0x78;
                  plStack_88 = (longlong *)0x0;
                  plStack_98 = (longlong *)0x0;
                  plStack_a0 = (longlong *)0x0;
                  plStack_b0 = (longlong *)0x0;
                  plStack_b8 = (longlong *)0x0;
                  goto LAB_23e277730;
                }
                uStack_80 = *(undefined8 *)(param_1 + 0x60);
                plVar8 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_78 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              plStack_90 = (longlong *)0x0;
              plVar12 = (longlong *)0x0;
              uVar15 = 0x76;
              plStack_88 = (longlong *)0x0;
              plStack_98 = (longlong *)0x0;
              plStack_a0 = (longlong *)0x0;
              plStack_b0 = (longlong *)0x0;
              plStack_b8 = (longlong *)0x0;
              plStack_a8 = (longlong *)0x0;
              goto LAB_23e277730;
            }
            uStack_80 = *(undefined8 *)(param_1 + 0x60);
            plVar8 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_78 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          }
          plStack_90 = (longlong *)0x0;
          plVar12 = (longlong *)0x0;
          plVar11 = (longlong *)0x0;
          uVar15 = 0x70;
          plStack_88 = (longlong *)0x0;
          plStack_98 = (longlong *)0x0;
          plStack_a0 = (longlong *)0x0;
          plStack_b0 = (longlong *)0x0;
          plStack_b8 = (longlong *)0x0;
          plStack_a8 = (longlong *)0x0;
          goto LAB_23e277730;
        }
        uStack_80 = *(undefined8 *)(param_1 + 0x60);
        plVar8 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_78 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      plStack_90 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      plVar10 = (longlong *)0x0;
      plStack_88 = (longlong *)0x0;
      uVar15 = 0x6a;
      plStack_98 = (longlong *)0x0;
      plStack_a0 = (longlong *)0x0;
      plStack_b0 = (longlong *)0x0;
      plStack_b8 = (longlong *)0x0;
      plStack_a8 = (longlong *)0x0;
      goto LAB_23e277730;
    }
    uStack_80 = *(undefined8 *)(param_1 + 0x60);
    plVar8 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_78 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  plStack_90 = (longlong *)0x0;
  plVar12 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  plStack_88 = (longlong *)0x0;
  plVar10 = (longlong *)0x0;
  uVar15 = 0x65;
  plStack_98 = (longlong *)0x0;
  plStack_a0 = (longlong *)0x0;
  plStack_b0 = (longlong *)0x0;
  plStack_b8 = (longlong *)0x0;
  plStack_a8 = (longlong *)0x0;
LAB_23e277730:
  plVar13 = DAT_23ed6a4f8;
  if (plVar8 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar8 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar8;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar6 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
    lVar6 = *(longlong *)(lVar6 + 0x10);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar6 = *(longlong *)(lVar6 + 0x2e8);
    lVar16 = plVar13[-1];
    puVar2 = *(undefined8 **)(lVar6 + 8);
    *puVar2 = plVar13 + -2;
    plVar13[-2] = lVar6;
    plVar13[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar6 + 8) = plVar13 + -2;
    plVar14 = plVar13;
  }
  else {
    plVar14 = plVar8;
    if ((longlong *)plVar8[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar14 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar14;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar13[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar15;
      pcVar4 = _PyRuntime_exref;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar6 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
      lVar16 = plVar13[-1];
      puVar2 = *(undefined8 **)(lVar6 + 8);
      *puVar2 = plVar13 + -2;
      plVar13[-2] = lVar6;
      plVar13[-1] = (ulonglong)((uint)lVar16 & 3) | (ulonglong)puVar2;
      lVar16 = *plVar8;
      *(longlong **)(lVar6 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar8;
      plVar14 = plVar13;
      if (lVar16 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  FUN_23e8bba40(plVar3,"ooooooooooooo",param_3,plVar7,plVar9,plVar10,plVar11,plStack_a8,plVar12,
                plStack_b8,plStack_b0,plStack_a0,plStack_98,plStack_88,plStack_90);
  if (_DAT_23eeb0738 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb0738 = (longlong *)0x0;
  }
  lVar6 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar8 = *(longlong **)(lVar6 + 0x28);
  plVar3 = (longlong *)plVar8[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar6 + 0x30);
  *(undefined4 *)(plVar8 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar8[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar8 = *plVar8 + -1;
  if (*plVar8 == 0) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  plVar8[0xf] = 0;
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plStack_a8 != (longlong *)0x0) &&
     (lVar6 = *plStack_a8, *plStack_a8 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_a8[1] + 0x30))(plStack_a8);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_b8 != (longlong *)0x0) &&
     (lVar6 = *plStack_b8, *plStack_b8 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_b8[1] + 0x30))(plStack_b8);
  }
  if ((plStack_b0 != (longlong *)0x0) &&
     (lVar6 = *plStack_b0, *plStack_b0 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_b0[1] + 0x30))(plStack_b0);
  }
  if ((plStack_a0 != (longlong *)0x0) &&
     (lVar6 = *plStack_a0, *plStack_a0 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_a0[1] + 0x30))(plStack_a0);
  }
  if ((plStack_98 != (longlong *)0x0) &&
     (lVar6 = *plStack_98, *plStack_98 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_98[1] + 0x30))(plStack_98);
  }
  if ((plStack_88 != (longlong *)0x0) &&
     (lVar6 = *plStack_88, *plStack_88 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_88[1] + 0x30))(plStack_88);
  }
  if ((plStack_90 != (longlong *)0x0) &&
     (lVar6 = *plStack_90, *plStack_90 = lVar6 + -1, lVar6 + -1 == 0)) {
    (**(code **)(plStack_90[1] + 0x30))(plStack_90);
  }
  lVar6 = *param_3;
  *param_3 = lVar6 + -1;
  if (lVar6 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,uStack_80,uStack_78,plVar14);
  return (code *)0x0;
}
