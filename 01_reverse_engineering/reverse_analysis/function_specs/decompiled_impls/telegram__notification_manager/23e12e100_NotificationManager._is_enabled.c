/* ===== 23e12e100 telegram.notification_manager:40 ===== */
/* ghidra_name=FUN_23e12e100 entry=23e12e100 size=9749 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e12e100(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  undefined1 auVar6 [16];
  undefined8 uVar7;
  code *pcVar8;
  char cVar9;
  int iVar10;
  uint uVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong lVar14;
  longlong *plVar15;
  code *pcVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  code *pcVar20;
  code *pcVar21;
  undefined4 uVar22;
  code *pcStack_120;
  code *pcStack_110;
  longlong *plStack_108;
  undefined1 auStack_f8 [16];
  code *apcStack_e8 [2];
  undefined1 auStack_d8 [16];
  code *apcStack_c8 [2];
  undefined1 auStack_b8 [16];
  code *apcStack_a8 [2];
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  longlong *plStack_70;
  code *pcStack_68;
  
  plVar12 = _DAT_23eeaadd0;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeaadd0 == (longlong *)0x0) {
LAB_23e12e149:
    _DAT_23eeaadd0 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaadc8,DAT_23eeaae08);
  }
  else {
    lVar14 = *_DAT_23eeaadd0;
    if (1 < lVar14) {
      *_DAT_23eeaadd0 = lVar14 + -1;
      goto LAB_23e12e149;
    }
    if (_DAT_23eeaadd0[2] != 0) {
      *_DAT_23eeaadd0 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      goto LAB_23e12e149;
    }
  }
  plVar4 = _DAT_23eeaadd0;
  lVar14 = *(longlong *)(param_1 + 0x38);
  plVar12 = _DAT_23eeaadd0 + 9;
  lVar3 = *(longlong *)(lVar14 + 8);
  _DAT_23eeaadd0[0xf] = lVar3;
  *(longlong **)(lVar14 + 8) = plVar12;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar12 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar12;
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  uVar13 = DAT_23eea8130;
  *(undefined4 *)(plVar4 + 8) = 0;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,uVar13);
  if (plVar12 == (longlong *)0x0) {
LAB_23e12e6c0:
    pcVar18 = (code *)0x0;
    pcStack_110 = *(code **)(param_1 + 0x68);
    pcVar16 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar12 = *(longlong **)(param_1 + 0x60);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar16 != (code *)0x0) {
      if (*(longlong **)(pcVar16 + 0x18) == plVar4) goto LAB_23e12e7b0;
LAB_23e12e6f7:
      pcVar18 = (code *)0x0;
      iVar10 = 0x2a;
      pcStack_120 = _PyRuntime_exref;
      pcVar21 = pcVar16;
LAB_23e12e714:
      pcVar16 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar16 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      *(int *)(pcVar16 + 0x24) = iVar10;
      lVar14 = *(longlong *)(pcStack_120 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
      lVar3 = *(longlong *)(pcVar16 + -8);
      plVar15 = *(longlong **)(lVar14 + 8);
      *plVar15 = (longlong)(pcVar16 + -0x10);
      *(longlong *)(pcVar16 + -0x10) = lVar14;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar15;
      lVar3 = *(longlong *)pcVar21;
      *(code **)(lVar14 + 8) = pcVar16 + -0x10;
      *(code **)(pcVar16 + 0x10) = pcVar21;
      if (lVar3 == 0) {
        (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
      }
      goto LAB_23e12e7b0;
    }
LAB_23e12eed3:
    pcVar18 = (code *)0x0;
    iVar10 = 0x2a;
    pcStack_120 = _PyRuntime_exref;
  }
  else {
    iVar10 = FUN_23a35f020(plVar12);
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))(plVar12);
    }
    if (iVar10 == -1) {
      pcStack_110 = *(code **)(param_1 + 0x68);
      pcVar16 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar12 = *(longlong **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar16 != (code *)0x0) {
        if (*(longlong **)(pcVar16 + 0x18) == plVar4) {
LAB_23e12f18c:
          pcVar18 = (code *)0x0;
          goto LAB_23e12e7b0;
        }
        goto LAB_23e12e6f7;
      }
      goto LAB_23e12eed3;
    }
    if (iVar10 != 0) {
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8138);
      if (plVar12 == (longlong *)0x0) goto LAB_23e12e6c0;
      uVar11 = FUN_23a35f020(plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (uVar11 == 0xffffffff) {
        pcStack_110 = *(code **)(param_1 + 0x68);
        pcVar16 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar12 = *(longlong **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (pcVar16 != (code *)0x0) {
          if (plVar4 != *(longlong **)(pcVar16 + 0x18)) goto LAB_23e12e6f7;
          goto LAB_23e12f18c;
        }
        goto LAB_23e12eed3;
      }
      if ((uVar11 & 1) == 0) goto LAB_23e12e210;
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
      if (plVar12 == (longlong *)0x0) {
LAB_23e12e8d0:
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        apcStack_c8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = *(longlong **)(param_1 + 0x138);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_108 == (longlong *)0x0) goto joined_r0x00023e12f613;
        *plStack_108 = *plStack_108 + 1;
joined_r0x00023e12e915:
        if (apcStack_c8[0] == (code *)0x0) goto LAB_23e12f625;
LAB_23e12e91b:
        uVar22 = 0x33;
LAB_23e12e920:
        pcVar18 = (code *)0x0;
        pcStack_120 = _PyRuntime_exref;
        pcVar16 = _Py_NoneStruct_exref;
        pcVar21 = apcStack_c8[0];
        goto LAB_23e12e93f;
      }
      iVar10 = FUN_23a35f020(plVar12);
      lVar14 = *plVar12 + -1;
      if (iVar10 == -1) {
        auVar6 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcVar16 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = lVar14;
        if (lVar14 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        plStack_108 = *(longlong **)(param_1 + 0x138);
        auStack_d8 = auVar6;
        apcStack_c8[0] = pcVar16;
        if (plStack_108 == (longlong *)0x0) goto joined_r0x00023e12f613;
LAB_23e12f2b1:
        *plStack_108 = *plStack_108 + 1;
        apcStack_c8[0] = pcVar16;
        if (pcVar16 != (code *)0x0) {
          uVar22 = 0x33;
          goto LAB_23e12e920;
        }
LAB_23e12f625:
        uVar22 = 0x33;
LAB_23e12f62b:
        pcVar18 = (code *)0x0;
        pcStack_120 = _PyRuntime_exref;
        pcVar16 = _Py_NoneStruct_exref;
        goto LAB_23e12f64a;
      }
      *plVar12 = lVar14;
      if (lVar14 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (iVar10 != 0) {
        plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
        if (plVar12 == (longlong *)0x0) goto LAB_23e12e8d0;
        *(undefined4 *)(plVar4 + 5) = 0x33;
        plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar12,_DAT_23eea8188);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        if (plVar15 != (longlong *)0x0) {
          iVar10 = FUN_23a35f020(plVar15);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if (iVar10 == -1) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            pcVar16 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_108 = *(longlong **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            apcStack_c8[0] = pcVar16;
            if (plStack_108 != (longlong *)0x0) goto LAB_23e12f2b1;
            goto joined_r0x00023e12f613;
          }
          if (iVar10 != 0) goto LAB_23e12e3df;
          plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
          if (plVar12 == (longlong *)0x0) {
            auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
            apcStack_c8[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            plStack_108 = *(longlong **)(param_1 + 0x138);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (plStack_108 == (longlong *)0x0) {
              if (apcStack_c8[0] == (code *)0x0) {
LAB_23e13023f:
                plStack_108 = (longlong *)0x0;
                uVar22 = 0x34;
                goto LAB_23e12f62b;
              }
            }
            else {
              *plStack_108 = *plStack_108 + 1;
              if (apcStack_c8[0] == (code *)0x0) goto LAB_23e12fe4e;
            }
LAB_23e12f983:
            uVar22 = 0x34;
          }
          else {
            *(undefined4 *)(plVar4 + 5) = 0x34;
            plVar15 = (longlong *)FUN_23e91bfe0(param_1,plVar12);
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            if (plVar15 == (longlong *)0x0) {
              auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
              apcStack_c8[0] = *(code **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              plStack_108 = *(longlong **)(param_1 + 0x138);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              if (plStack_108 != (longlong *)0x0) {
                *plStack_108 = *plStack_108 + 1;
                if (apcStack_c8[0] != (code *)0x0) goto LAB_23e12f983;
LAB_23e12fe4e:
                uVar22 = 0x34;
                goto LAB_23e12f62b;
              }
              if (apcStack_c8[0] == (code *)0x0) goto LAB_23e13023f;
              uVar22 = 0x34;
            }
            else {
              iVar10 = FUN_23a35f020(plVar15);
              lVar14 = *plVar15 + -1;
              if (iVar10 == -1) {
                auVar6 = *(undefined1 (*) [16])(param_1 + 0x60);
                pcVar16 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar15 = lVar14;
                if (lVar14 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                plStack_108 = *(longlong **)(param_1 + 0x138);
                auStack_d8 = auVar6;
                apcStack_c8[0] = pcVar16;
                if (plStack_108 == (longlong *)0x0) {
                  if (pcVar16 == (code *)0x0) goto LAB_23e13023f;
                  uVar22 = 0x34;
                  plStack_108 = (longlong *)0x0;
                }
                else {
                  *plStack_108 = *plStack_108 + 1;
                  if (pcVar16 == (code *)0x0) goto LAB_23e12fe4e;
                  uVar22 = 0x34;
                }
              }
              else {
                *plVar15 = lVar14;
                if (lVar14 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                if (iVar10 == 0) {
                  plVar12 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
                  if (plVar12 == (longlong *)0x0) {
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    apcStack_c8[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_108 = *(longlong **)(param_1 + 0x138);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_108 != (longlong *)0x0) {
                      *plStack_108 = *plStack_108 + 1;
                      goto joined_r0x00023e130530;
                    }
                    if (apcStack_c8[0] == (code *)0x0) {
LAB_23e13077b:
                      uVar22 = 0x37;
                      plStack_108 = (longlong *)0x0;
                      goto LAB_23e12f62b;
                    }
                  }
                  else {
                    *(undefined4 *)(plVar4 + 5) = 0x37;
                    plVar15 = (longlong *)FUN_23e915840(param_1,plVar12,_DAT_23eea81a0,plVar2);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    if (plVar15 != (longlong *)0x0) {
                      *plVar15 = *plVar15 + -1;
                      pcVar16 = _Py_NoneStruct_exref;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                        pcVar16 = _Py_NoneStruct_exref;
                      }
                      goto LAB_23e12e24d;
                    }
                    auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    apcStack_c8[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_108 = *(longlong **)(param_1 + 0x138);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plStack_108 == (longlong *)0x0) {
                      if (apcStack_c8[0] != (code *)0x0) {
                        uVar22 = 0x37;
                        goto LAB_23e12e920;
                      }
                      goto LAB_23e13077b;
                    }
                    *plStack_108 = *plStack_108 + 1;
joined_r0x00023e130530:
                    if (apcStack_c8[0] == (code *)0x0) {
                      uVar22 = 0x37;
                      goto LAB_23e12f62b;
                    }
                  }
                  uVar22 = 0x37;
                }
                else {
                  lVar14 = FUN_23e8ff8f0();
                  if (lVar14 == 0) {
                    FUN_23e915740(param_1,&plStack_78);
                    plStack_108 = *(longlong **)(param_1 + 0x138);
                    auStack_d8._8_8_ = plStack_70;
                    auStack_d8._0_8_ = plStack_78;
joined_r0x00023e130766:
                    apcStack_c8[0] = pcStack_68;
                    if (plStack_108 != (longlong *)0x0) {
                      *plStack_108 = *plStack_108 + 1;
                      apcStack_c8[0] = pcStack_68;
                      goto joined_r0x00023e130412;
                    }
joined_r0x00023e1306fb:
                    if (apcStack_c8[0] == (code *)0x0) {
                      uVar22 = 0x35;
                      plStack_108 = (longlong *)0x0;
                      goto LAB_23e12f62b;
                    }
                  }
                  else {
                    plVar12 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eea8198);
                    if (plVar12 == (longlong *)0x0) {
                      auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
                      pcStack_68 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_108 = *(longlong **)(param_1 + 0x138);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      goto joined_r0x00023e130766;
                    }
                    plVar15 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eea8140);
                    if (plVar15 == (longlong *)0x0) {
                      auVar6 = *(undefined1 (*) [16])(param_1 + 0x60);
                      pcVar16 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      plStack_108 = *(longlong **)(param_1 + 0x138);
                    }
                    else {
                      *(undefined4 *)(plVar4 + 5) = 0x35;
                      plStack_78 = plVar2;
                      plStack_70 = plVar15;
                      plVar17 = (longlong *)FUN_23e94ed00(param_1,plVar12);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      *plVar15 = *plVar15 + -1;
                      if (*plVar15 == 0) {
                        (**(code **)(plVar15[1] + 0x30))(plVar15);
                      }
                      if (plVar17 != (longlong *)0x0) {
                        *plVar17 = *plVar17 + -1;
                        pcVar16 = _Py_NoneStruct_exref;
                        if (*plVar17 == 0) {
                          (**(code **)(plVar17[1] + 0x30))(plVar17);
                          pcVar16 = _Py_NoneStruct_exref;
                        }
                        goto LAB_23e12e24d;
                      }
                      auVar6 = *(undefined1 (*) [16])(param_1 + 0x60);
                      pcVar16 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      plStack_108 = *(longlong **)(param_1 + 0x138);
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    }
                    auStack_d8 = auVar6;
                    apcStack_c8[0] = pcVar16;
                    if (plStack_108 == (longlong *)0x0) goto joined_r0x00023e1306fb;
                    *plStack_108 = *plStack_108 + 1;
joined_r0x00023e130412:
                    if (apcStack_c8[0] == (code *)0x0) {
                      uVar22 = 0x35;
                      goto LAB_23e12f62b;
                    }
                  }
                  uVar22 = 0x35;
                }
              }
            }
          }
          goto LAB_23e12e920;
        }
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        apcStack_c8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = *(longlong **)(param_1 + 0x138);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_108 != (longlong *)0x0) {
          *plStack_108 = *plStack_108 + 1;
          goto joined_r0x00023e12e915;
        }
joined_r0x00023e12f613:
        if (apcStack_c8[0] != (code *)0x0) goto LAB_23e12e91b;
        plStack_108 = (longlong *)0x0;
        goto LAB_23e12f625;
      }
LAB_23e12e3df:
      pcVar16 = _Py_NoneStruct_exref;
      cVar9 = FUN_23e8d9ac0(plVar1,DAT_23eea8140,_Py_NoneStruct_exref);
      if (cVar9 == '\0') {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        apcStack_c8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = *(longlong **)(param_1 + 0x138);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar21 = apcStack_c8[0];
        if (plStack_108 == (longlong *)0x0) {
          pcVar18 = (code *)0x0;
          if (apcStack_c8[0] == (code *)0x0) goto LAB_23e130032;
          uVar22 = 0x3b;
          pcStack_120 = _PyRuntime_exref;
        }
        else {
          *plStack_108 = *plStack_108 + 1;
          if (apcStack_c8[0] == (code *)0x0) {
LAB_23e130032:
            pcVar18 = (code *)0x0;
            uVar22 = 0x3b;
            pcStack_120 = _PyRuntime_exref;
            goto LAB_23e12f64a;
          }
          uVar22 = 0x3b;
          pcVar18 = (code *)0x0;
          pcStack_120 = _PyRuntime_exref;
        }
        goto LAB_23e12e93f;
      }
      lVar14 = FUN_23e8ff8f0();
      if (lVar14 == 0) {
        FUN_23e915740(param_1,&plStack_78,_DAT_23eea8148);
        pcVar18 = pcStack_68;
        auStack_b8._0_8_ = plStack_78;
        auStack_b8._8_8_ = plStack_70;
LAB_23e12fa99:
        plStack_108 = *(longlong **)(param_1 + 0x138);
        if (plStack_108 != (longlong *)0x0) {
          *plStack_108 = *plStack_108 + 1;
        }
        pcVar21 = DAT_23ed6a4f8;
        apcStack_a8[0] = pcVar18;
        if (pcVar18 == (code *)0x0) {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar18 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar18;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong *)(pcVar21 + 0x10) = 0;
          *(longlong **)(pcVar21 + 0x18) = plVar4;
          *plVar4 = *plVar4 + 1;
          *(longlong *)(pcVar21 + 0x20) = 0x3fffffffff;
          pcStack_120 = _PyRuntime_exref;
          lVar14 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = *(longlong *)(pcVar21 + -8);
          plVar12 = *(longlong **)(lVar14 + 8);
          *plVar12 = (longlong)(pcVar21 + -0x10);
          *(longlong *)(pcVar21 + -0x10) = lVar14;
          *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
          *(code **)(lVar14 + 8) = pcVar21 + -0x10;
          if ((apcStack_a8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
             *(longlong *)apcStack_a8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))(apcStack_a8[0]);
          }
        }
        else {
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            pcVar19 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar19;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          *(longlong **)(pcVar21 + 0x18) = plVar4;
          *plVar4 = *plVar4 + 1;
          *(longlong *)(pcVar21 + 0x20) = 0x3fffffffff;
          pcStack_120 = _PyRuntime_exref;
          lVar14 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = *(longlong *)(pcVar21 + -8);
          plVar12 = *(longlong **)(lVar14 + 8);
          *plVar12 = (longlong)(pcVar21 + -0x10);
          *(longlong *)(pcVar21 + -0x10) = lVar14;
          *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
          *(code **)(lVar14 + 8) = pcVar21 + -0x10;
          *(code **)(pcVar21 + 0x10) = pcVar18;
          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
          if ((apcStack_a8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
             *(longlong *)apcStack_a8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
          }
        }
        apcStack_a8[0] = pcVar21;
        if (((code *)auStack_b8._0_8_ != pcVar16) && ((code *)auStack_b8._0_8_ != (code *)0x0)) {
          FUN_23e91b1b0(param_1,auStack_b8,auStack_b8 + 8,apcStack_a8);
        }
        plVar12 = *(longlong **)(auStack_b8._8_8_ + 0x28);
        if (apcStack_a8[0] == pcVar16) {
          pcVar18 = (code *)0x0;
        }
        else {
          pcVar18 = apcStack_a8[0];
          if (apcStack_a8[0] != (code *)0x0) {
            *(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + 1;
          }
        }
        *(code **)(auStack_b8._8_8_ + 0x28) = pcVar18;
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        plVar12 = *(longlong **)(param_1 + 0x138);
        *(undefined8 *)(param_1 + 0x138) = auStack_b8._8_8_;
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))();
        }
        *(longlong *)auStack_b8._0_8_ = *(longlong *)auStack_b8._0_8_ + -1;
        if (*(longlong *)auStack_b8._0_8_ == 0) {
          (**(code **)(*(longlong *)(auStack_b8._0_8_ + 8) + 0x30))();
        }
        if ((apcStack_a8[0] != (code *)0x0) &&
           (*(longlong *)apcStack_a8[0] = *(longlong *)apcStack_a8[0] + -1,
           *(longlong *)apcStack_a8[0] == 0)) {
          (**(code **)(*(longlong *)(apcStack_a8[0] + 8) + 0x30))();
        }
        pcVar21 = PyExc_RuntimeError_exref;
        apcStack_a8[0] = (code *)0x0;
        auStack_b8 = (undefined1  [16])0x0;
        iVar10 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                               *(undefined8 *)PyExc_RuntimeError_exref);
        if (iVar10 == 0) {
          pcVar18 = *(code **)(param_1 + 0x138);
          if ((pcVar18 == (code *)0x0) || (pcVar18 == pcVar16)) {
            pcVar21 = *(code **)pcVar21;
            auStack_d8._8_8_ = PyUnicode_FromString("No active exception to reraise");
            pcVar18 = *(code **)(param_1 + 0x138);
            *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
            *(longlong **)(param_1 + 0x138) = plStack_108;
            if (pcVar18 != (code *)0x0) {
              iVar10 = 0x3e;
              pcVar19 = (code *)0x0;
              goto LAB_23e12ffcf;
            }
            auStack_d8._0_8_ = pcVar21;
            iVar10 = 0x3e;
            apcStack_c8[0] = (code *)0x0;
            if (plStack_108 == (longlong *)0x0) goto LAB_23e130364;
LAB_23e13000d:
            *plStack_108 = *plStack_108 + 1;
          }
          else {
            pcVar21 = *(code **)(pcVar18 + 8);
            pcVar19 = *(code **)(pcVar18 + 0x28);
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
            *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
            iVar10 = 0;
            auStack_d8._8_8_ = pcVar18;
            if ((pcVar19 == (code *)0x0) ||
               (*(longlong *)pcVar19 = *(longlong *)pcVar19 + 1,
               plVar4 != *(longlong **)(pcVar19 + 0x18))) {
              *(longlong **)(param_1 + 0x138) = plStack_108;
            }
            else {
              *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar19 + 0x24);
              *(longlong **)(param_1 + 0x138) = plStack_108;
            }
LAB_23e12ffcf:
            *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
            if (*(longlong *)pcVar18 == 0) {
              (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))();
              plStack_108 = *(longlong **)(param_1 + 0x138);
            }
            auStack_d8._0_8_ = pcVar21;
            apcStack_c8[0] = pcVar19;
            if (plStack_108 != (longlong *)0x0) goto LAB_23e13000d;
          }
          if (apcStack_c8[0] == (code *)0x0) {
            if (iVar10 == 0) {
              uVar22 = (undefined4)plVar4[5];
              pcVar18 = (code *)0x0;
              goto LAB_23e12f64a;
            }
LAB_23e130364:
            pcVar18 = (code *)0x0;
            uVar22 = 0x3e;
            goto LAB_23e12f64a;
          }
          if (iVar10 == 0) {
            pcVar18 = (code *)0x0;
            goto LAB_23e12e9eb;
          }
          uVar22 = 0x3e;
          pcVar18 = (code *)0x0;
          pcVar21 = apcStack_c8[0];
          goto LAB_23e12e93f;
        }
        plVar12 = *(longlong **)(param_1 + 0x138);
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
        *(longlong **)(param_1 + 0x138) = plStack_108;
        pcVar18 = pcVar16;
        if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      else {
        *(undefined4 *)(plVar4 + 5) = 0x3f;
        pcVar18 = (code *)FUN_23e91bfe0(param_1,lVar14,_DAT_23eea81a8);
        if (pcVar18 == (code *)0x0) {
          pcVar18 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          auStack_b8._0_8_ = *(undefined8 *)(param_1 + 0x60);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          auStack_b8._8_8_ = *(longlong **)(param_1 + 0x68);
          goto LAB_23e12fa99;
        }
      }
      iVar10 = FUN_23a35f020(pcVar18);
      if (iVar10 == -1) goto LAB_23e12f9b8;
      if (iVar10 == 0) {
LAB_23e12f31c:
        lVar14 = FUN_23e8ff8f0();
        if (lVar14 == 0) {
          FUN_23e915740(param_1,&plStack_78,_DAT_23eea8148);
          plStack_108 = *(longlong **)(param_1 + 0x138);
          apcStack_c8[0] = pcStack_68;
          auStack_d8._8_8_ = plStack_70;
          auStack_d8._0_8_ = plStack_78;
          if (plStack_108 != (longlong *)0x0) goto LAB_23e12f390;
LAB_23e13058e:
          apcStack_c8[0] = pcStack_68;
          if (pcStack_68 == (code *)0x0) {
            plStack_108 = (longlong *)0x0;
            goto LAB_23e13059e;
          }
        }
        else {
          *(undefined4 *)(plVar4 + 5) = 0x47;
          plVar12 = (longlong *)FUN_23e915840(param_1,lVar14,_DAT_23eea81b8,plVar2);
          if (plVar12 != (longlong *)0x0) {
LAB_23e12ecc5:
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
LAB_23e12eccf:
            lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar12 = *(longlong **)(lVar14 + 0x28);
            plVar4 = (longlong *)plVar12[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
            *(undefined4 *)(plVar12 + 8) = 0xffffffff;
            if (plVar4 != (longlong *)0x0) {
              plVar12[2] = 0;
              *plVar4 = *plVar4 + -1;
              if (*plVar4 == 0) {
                (**(code **)(plVar4[1] + 0x30))();
              }
            }
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
            plVar12[0xf] = 0;
            goto LAB_23e12e2a7;
          }
          auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
          pcStack_68 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          plStack_108 = *(longlong **)(param_1 + 0x138);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          apcStack_c8[0] = pcStack_68;
          if (plStack_108 == (longlong *)0x0) goto LAB_23e13058e;
LAB_23e12f390:
          *plStack_108 = *plStack_108 + 1;
          if (apcStack_c8[0] == (code *)0x0) {
LAB_23e13059e:
            uVar22 = 0x47;
            pcStack_120 = _PyRuntime_exref;
            goto LAB_23e12f64a;
          }
        }
        uVar22 = 0x47;
        pcStack_120 = _PyRuntime_exref;
        pcVar21 = apcStack_c8[0];
LAB_23e12e93f:
        pcVar19 = DAT_23ed6a4f8;
        if (DAT_23ed6a4f8 == (code *)0x0) {
          pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
          pcVar20 = apcStack_c8[0];
        }
        else {
          pcVar20 = *(code **)DAT_23ed6a4f8;
          *(undefined8 *)DAT_23ed6a4f8 = 1;
          DAT_23ed6a4f8 = pcVar20;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          pcVar20 = pcVar21;
        }
        *(longlong **)(pcVar19 + 0x18) = plVar4;
        *plVar4 = *plVar4 + 1;
        lVar14 = *(longlong *)(pcStack_120 + 0x1f8);
        *(undefined4 *)(pcVar19 + 0x24) = uVar22;
        *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
        lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
        lVar3 = *(longlong *)(pcVar19 + -8);
        plVar12 = *(longlong **)(lVar14 + 8);
        *plVar12 = (longlong)(pcVar19 + -0x10);
        *(longlong *)(pcVar19 + -0x10) = lVar14;
        *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
        *(code **)(lVar14 + 8) = pcVar19 + -0x10;
        *(code **)(pcVar19 + 0x10) = pcVar21;
        *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
        do {
          if ((pcVar20 != (code *)0x0) &&
             (*(longlong *)pcVar20 = *(longlong *)pcVar20 + -1, *(longlong *)pcVar20 == 0)) {
            (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))();
          }
          pcVar21 = (code *)auStack_d8._0_8_;
          apcStack_c8[0] = pcVar19;
LAB_23e12e9eb:
          if ((pcVar21 != pcVar16) && (pcVar21 != (code *)0x0)) {
            FUN_23e91b1b0(param_1,auStack_d8,auStack_d8 + 8,apcStack_c8);
          }
          plVar12 = *(longlong **)(auStack_d8._8_8_ + 0x28);
          if (apcStack_c8[0] == pcVar16) {
            pcVar21 = (code *)0x0;
          }
          else {
            pcVar21 = apcStack_c8[0];
            if (apcStack_c8[0] != (code *)0x0) {
              *(longlong *)apcStack_c8[0] = *(longlong *)apcStack_c8[0] + 1;
            }
          }
          *(code **)(auStack_d8._8_8_ + 0x28) = pcVar21;
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))();
          }
          plVar12 = *(longlong **)(param_1 + 0x138);
          *(undefined8 *)(param_1 + 0x138) = auStack_d8._8_8_;
          if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
            (**(code **)(plVar12[1] + 0x30))();
          }
          *(longlong *)auStack_d8._0_8_ = *(longlong *)auStack_d8._0_8_ + -1;
          if (*(longlong *)auStack_d8._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_d8._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_c8[0] != (code *)0x0) &&
             (*(longlong *)apcStack_c8[0] = *(longlong *)apcStack_c8[0] + -1,
             *(longlong *)apcStack_c8[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_c8[0] + 8) + 0x30))();
          }
          apcStack_c8[0] = (code *)0x0;
          auStack_d8 = (undefined1  [16])0x0;
          iVar10 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                 *(undefined8 *)PyExc_Exception_exref);
          if (iVar10 == 0) {
            pcVar21 = *(code **)(param_1 + 0x138);
            if ((pcVar21 == pcVar16) || (pcVar21 == (code *)0x0)) {
              plVar12 = *(longlong **)PyExc_RuntimeError_exref;
              pcStack_110 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar21 = *(code **)(param_1 + 0x138);
              iVar10 = 0x31;
              *plVar12 = *plVar12 + 1;
              *(longlong **)(param_1 + 0x138) = plStack_108;
              if ((pcVar21 == (code *)0x0) ||
                 (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 != 0))
              goto LAB_23e12eef0;
              pcVar16 = (code *)0x0;
            }
            else {
              plVar12 = *(longlong **)(pcVar21 + 8);
              pcVar16 = *(code **)(pcVar21 + 0x28);
              *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
              *plVar12 = *plVar12 + 1;
              iVar10 = 0;
              pcStack_110 = pcVar21;
              if (pcVar16 == (code *)0x0) {
                *(longlong **)(param_1 + 0x138) = plStack_108;
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                if (*(longlong *)pcVar21 != 0) goto LAB_23e12f21b;
              }
              else {
                *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                if (*(longlong **)(pcVar16 + 0x18) == plVar4) {
                  *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar16 + 0x24);
                }
                *(longlong **)(param_1 + 0x138) = plStack_108;
                *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                if (*(longlong *)pcVar21 != 0) goto LAB_23e12ee89;
              }
            }
LAB_23e12eeb5:
            (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))();
LAB_23e12ee80:
            if (pcVar16 != (code *)0x0) goto LAB_23e12ee89;
            if (iVar10 == 0) goto LAB_23e12f21b;
            goto LAB_23e12eef0;
          }
          pcVar21 = *(code **)(param_1 + 0x138);
          *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
          uVar13 = FUN_23a3a0d40(DAT_23ed6cf28);
          plVar12 = _DAT_23eea81c0;
          lVar14 = *(longlong *)(param_1 + 0x10);
          plVar15 = *(longlong **)(lVar14 + 0xe20);
          if (plVar15 == (longlong *)0x0) {
            plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar3 = plVar15[3];
            *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
            *(longlong *)(lVar14 + 0xe20) = lVar3;
            *plVar15 = 1;
          }
          plVar15[4] = 0;
          lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_120 + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar15[-1];
          puVar5 = *(undefined8 **)(lVar14 + 8);
          *puVar5 = plVar15 + -2;
          plVar15[-2] = lVar14;
          plVar15[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
          *(longlong **)(lVar14 + 8) = plVar15 + -2;
          plVar17 = DAT_23ed6a4c0;
          *plVar12 = *plVar12 + 1;
          plVar15[3] = (longlong)plVar12;
          uVar7 = DAT_23ed6cd28;
          if (plVar17 != (longlong *)0x0) {
LAB_23e12ebae:
            auStack_98._8_8_ = uVar7;
            auStack_98._0_8_ = pcVar21;
            lVar14 = FUN_23e94ed00(param_1,plVar17,auStack_98);
            if (lVar14 == 0) {
              pcStack_110 = *(code **)(param_1 + 0x68);
              plVar12 = *(longlong **)(param_1 + 0x60);
              iVar10 = 0x49;
              pcVar16 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              lVar14 = *plVar15;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *plVar15 = lVar14 + -1;
              if (lVar14 + -1 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
                iVar10 = 0x49;
              }
            }
            else {
              plVar15[4] = lVar14;
              plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (plVar12 != (longlong *)0x0) {
                *(undefined4 *)(plVar4 + 5) = 0x49;
                plVar15 = (longlong *)FUN_23e914090(param_1,uVar13);
                *plVar12 = *plVar12 + -1;
                if (*plVar12 == 0) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if (plVar15 != (longlong *)0x0) {
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))(plVar15);
                  }
                  *(undefined4 *)(plVar4 + 5) = 0x4b;
                  plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar2,DAT_23ed6cf10);
                  if (plVar12 == (longlong *)0x0) {
                    auStack_f8 = *(undefined1 (*) [16])(param_1 + 0x60);
                    pcVar19 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plVar15 = *(longlong **)(param_1 + 0x138);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (plVar15 != (longlong *)0x0) {
                      *plVar15 = *plVar15 + 1;
                    }
                    pcVar20 = DAT_23ed6a4f8;
                    apcStack_e8[0] = pcVar19;
                    if (pcVar19 == (code *)0x0) {
                      if (DAT_23ed6a4f8 == (code *)0x0) {
                        pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        pcVar19 = *(code **)DAT_23ed6a4f8;
                        *(undefined8 *)DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = pcVar19;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      *(longlong *)(pcVar20 + 0x10) = 0;
                      *(longlong **)(pcVar20 + 0x18) = plVar4;
                      *plVar4 = *plVar4 + 1;
                      *(longlong *)(pcVar20 + 0x20) = 0x4bffffffff;
                      lVar14 = *(longlong *)
                                (*(longlong *)(*(longlong *)(pcStack_120 + 0x1f8) + 0x10) + 0x2e8);
                      lVar3 = *(longlong *)(pcVar20 + -8);
                      plVar12 = *(longlong **)(lVar14 + 8);
                      *plVar12 = (longlong)(pcVar20 + -0x10);
                      *(longlong *)(pcVar20 + -0x10) = lVar14;
                      *(ulonglong *)(pcVar20 + -8) =
                           (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
                      *(code **)(lVar14 + 8) = pcVar20 + -0x10;
                      if ((apcStack_e8[0] != (code *)0x0) &&
                         (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
                         *(longlong *)apcStack_e8[0] == 0)) {
                        (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))(apcStack_e8[0]);
                      }
                    }
                    else {
                      if (DAT_23ed6a4f8 == (code *)0x0) {
                        pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        pcVar8 = *(code **)DAT_23ed6a4f8;
                        *(undefined8 *)DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = pcVar8;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      *(longlong **)(pcVar20 + 0x18) = plVar4;
                      *plVar4 = *plVar4 + 1;
                      *(longlong *)(pcVar20 + 0x20) = 0x4bffffffff;
                      lVar14 = *(longlong *)
                                (*(longlong *)(*(longlong *)(pcStack_120 + 0x1f8) + 0x10) + 0x2e8);
                      lVar3 = *(longlong *)(pcVar20 + -8);
                      plVar12 = *(longlong **)(lVar14 + 8);
                      *plVar12 = (longlong)(pcVar20 + -0x10);
                      *(longlong *)(pcVar20 + -0x10) = lVar14;
                      *(ulonglong *)(pcVar20 + -8) =
                           (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
                      *(code **)(lVar14 + 8) = pcVar20 + -0x10;
                      *(code **)(pcVar20 + 0x10) = pcVar19;
                      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                      if ((apcStack_e8[0] != (code *)0x0) &&
                         (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
                         *(longlong *)apcStack_e8[0] == 0)) {
                        (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
                      }
                    }
                    apcStack_e8[0] = pcVar20;
                    if (((code *)auStack_f8._0_8_ != (code *)0x0) &&
                       ((code *)auStack_f8._0_8_ != pcVar16)) {
                      FUN_23e91b1b0(param_1,auStack_f8,auStack_f8 + 8,apcStack_e8);
                    }
                    plVar12 = *(longlong **)(auStack_f8._8_8_ + 0x28);
                    if (apcStack_e8[0] == pcVar16) {
                      pcVar19 = (code *)0x0;
                    }
                    else {
                      pcVar19 = apcStack_e8[0];
                      if (apcStack_e8[0] != (code *)0x0) {
                        *(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + 1;
                      }
                    }
                    *(code **)(auStack_f8._8_8_ + 0x28) = pcVar19;
                    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    plVar12 = *(longlong **)(param_1 + 0x138);
                    *(undefined8 *)(param_1 + 0x138) = auStack_f8._8_8_;
                    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                    *(longlong *)auStack_f8._0_8_ = *(longlong *)auStack_f8._0_8_ + -1;
                    if (*(longlong *)auStack_f8._0_8_ == 0) {
                      (**(code **)(*(longlong *)(auStack_f8._0_8_ + 8) + 0x30))();
                    }
                    if ((apcStack_e8[0] != (code *)0x0) &&
                       (*(longlong *)apcStack_e8[0] = *(longlong *)apcStack_e8[0] + -1,
                       *(longlong *)apcStack_e8[0] == 0)) {
                      (**(code **)(*(longlong *)(apcStack_e8[0] + 8) + 0x30))();
                    }
                    apcStack_e8[0] = (code *)0x0;
                    auStack_f8 = (undefined1  [16])0x0;
                    iVar10 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                    (*(longlong *)(param_1 + 0x138) + 8),
                                           *(undefined8 *)PyExc_Exception_exref);
                    if (iVar10 == 0) {
                      pcVar19 = *(code **)(param_1 + 0x138);
                      if ((pcVar19 == pcVar16) || (pcVar19 == (code *)0x0)) {
                        plVar12 = *(longlong **)PyExc_RuntimeError_exref;
                        pcStack_110 = (code *)PyUnicode_FromString("No active exception to reraise")
                        ;
                        pcVar19 = *(code **)(param_1 + 0x138);
                        *plVar12 = *plVar12 + 1;
                        *(longlong **)(param_1 + 0x138) = plVar15;
                        if (pcVar19 == (code *)0x0) {
                          iVar10 = 0x4a;
                          pcVar16 = (code *)0x0;
                          goto LAB_23e12ee49;
                        }
                        iVar10 = 0x4a;
                        pcVar16 = (code *)0x0;
                      }
                      else {
                        plVar12 = *(longlong **)(pcVar19 + 8);
                        pcVar16 = *(code **)(pcVar19 + 0x28);
                        *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
                        *plVar12 = *plVar12 + 1;
                        iVar10 = 0;
                        pcStack_110 = pcVar19;
                        if (pcVar16 == (code *)0x0) {
                          *(longlong **)(param_1 + 0x138) = plVar15;
                        }
                        else {
                          *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
                          if (plVar4 == *(longlong **)(pcVar16 + 0x18)) {
                            *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar16 + 0x24);
                          }
                          *(longlong **)(param_1 + 0x138) = plVar15;
                        }
                      }
                      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                      if (*(longlong *)pcVar19 == 0) {
                        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
                      }
                      goto LAB_23e12ee49;
                    }
                    plVar12 = *(longlong **)(param_1 + 0x138);
                    *(longlong **)(param_1 + 0x138) = plVar15;
                    if (plVar12 != (longlong *)0x0) goto LAB_23e12ec90;
                  }
                  else {
LAB_23e12ec90:
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))();
                    }
                  }
                  *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
                  if (*(longlong *)pcVar21 == 0) {
                    (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
                  }
                  plVar12 = *(longlong **)(param_1 + 0x138);
                  *(longlong **)(param_1 + 0x138) = plStack_108;
                  if (plVar12 != (longlong *)0x0) goto LAB_23e12ecc5;
                  goto LAB_23e12eccf;
                }
              }
              pcStack_110 = *(code **)(param_1 + 0x68);
              plVar12 = *(longlong **)(param_1 + 0x60);
              iVar10 = 0x49;
              pcVar16 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
            }
LAB_23e12ee49:
            *(longlong *)pcVar21 = *(longlong *)pcVar21 + -1;
            if (*(longlong *)pcVar21 == 0) {
              (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
            }
            pcVar21 = *(code **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plStack_108;
            if ((pcVar21 != (code *)0x0) &&
               (*(longlong *)pcVar21 = *(longlong *)pcVar21 + -1, *(longlong *)pcVar21 == 0))
            goto LAB_23e12eeb5;
            goto LAB_23e12ee80;
          }
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar17 != (longlong *)0x0) {
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
            goto LAB_23e12ebae;
          }
          PyErr_PrintEx(0);
          Py_Exit(1);
LAB_23e130269:
          if (pcVar21 != (code *)0x0) goto LAB_23e12fa03;
          plStack_108 = (longlong *)0x0;
LAB_23e130279:
          uVar22 = 0x43;
          pcStack_120 = _PyRuntime_exref;
LAB_23e12f64a:
          pcVar19 = DAT_23ed6a4f8;
          if (DAT_23ed6a4f8 == (code *)0x0) {
            pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
            pcVar20 = apcStack_c8[0];
          }
          else {
            pcVar21 = *(code **)DAT_23ed6a4f8;
            *(undefined8 *)DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = pcVar21;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            pcVar20 = (code *)0x0;
          }
          *(longlong *)(pcVar19 + 0x10) = 0;
          *(longlong **)(pcVar19 + 0x18) = plVar4;
          *plVar4 = *plVar4 + 1;
          lVar14 = *(longlong *)(pcStack_120 + 0x1f8);
          *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
          lVar14 = *(longlong *)(lVar14 + 0x10);
          *(undefined4 *)(pcVar19 + 0x24) = uVar22;
          lVar14 = *(longlong *)(lVar14 + 0x2e8);
          lVar3 = *(longlong *)(pcVar19 + -8);
          plVar12 = *(longlong **)(lVar14 + 8);
          *plVar12 = (longlong)(pcVar19 + -0x10);
          *(longlong *)(pcVar19 + -0x10) = lVar14;
          *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
          *(code **)(lVar14 + 8) = pcVar19 + -0x10;
        } while( true );
      }
      *(undefined4 *)(plVar4 + 5) = 0x43;
      plVar12 = (longlong *)FUN_23e91bfe0(param_1,pcVar18,_DAT_23eea8188);
      if (plVar12 == (longlong *)0x0) {
LAB_23e12f9b8:
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = *(longlong **)(param_1 + 0x138);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        apcStack_c8[0] = pcVar21;
        if (plStack_108 == (longlong *)0x0) goto LAB_23e130269;
        *plStack_108 = *plStack_108 + 1;
        if (pcVar21 == (code *)0x0) goto LAB_23e130279;
        goto LAB_23e12fa03;
      }
      iVar10 = FUN_23a35f020(plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (iVar10 == -1) goto LAB_23e12f9b8;
      if (iVar10 != 0) goto LAB_23e12f31c;
      *(undefined4 *)(plVar4 + 5) = 0x44;
      plVar12 = (longlong *)FUN_23e915840(param_1,pcVar18,_DAT_23eea81b0,plVar2);
      if (plVar12 == (longlong *)0x0) {
        auStack_d8 = *(undefined1 (*) [16])(param_1 + 0x60);
        apcStack_c8[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        plStack_108 = *(longlong **)(param_1 + 0x138);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (plStack_108 != (longlong *)0x0) {
          *plStack_108 = *plStack_108 + 1;
        }
        if (apcStack_c8[0] == (code *)0x0) {
          uVar22 = 0x44;
          pcStack_120 = _PyRuntime_exref;
          goto LAB_23e12f64a;
        }
        uVar22 = 0x44;
        pcStack_120 = _PyRuntime_exref;
        pcVar21 = apcStack_c8[0];
        goto LAB_23e12e93f;
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      lVar14 = *(longlong *)pcVar16;
LAB_23e12e258:
      *(longlong *)pcVar16 = lVar14 + 1;
      lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar12 = *(longlong **)(lVar14 + 0x28);
      plVar4 = (longlong *)plVar12[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
      *(undefined4 *)(plVar12 + 8) = 0xffffffff;
      if (plVar4 != (longlong *)0x0) {
        plVar12[2] = 0;
        *plVar4 = *plVar4 + -1;
        if (*plVar4 == 0) {
          (**(code **)(plVar4[1] + 0x30))();
        }
      }
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar12[0xf] = 0;
LAB_23e12e2a7:
      if ((pcVar18 != (code *)0x0) &&
         (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
        (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
      }
      *plVar1 = *plVar1 + -1;
      if (*plVar1 == 0) {
        (**(code **)(plVar1[1] + 0x30))(plVar1);
      }
      *plVar2 = *plVar2 + -1;
      if (*plVar2 != 0) {
        return pcVar16;
      }
      (**(code **)(plVar2[1] + 0x30))(plVar2);
      return pcVar16;
    }
LAB_23e12e210:
    *(undefined4 *)(plVar4 + 5) = 0x2c;
    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar2,DAT_23ed6cf10);
    if (plVar12 != (longlong *)0x0) {
      *plVar12 = *plVar12 + -1;
      pcVar16 = _Py_NoneStruct_exref;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
LAB_23e12e24d:
      lVar14 = *(longlong *)pcVar16;
      pcVar18 = (code *)0x0;
      goto LAB_23e12e258;
    }
    auStack_98 = *(undefined1 (*) [16])(param_1 + 0x60);
    pcVar16 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar15 = *(longlong **)(param_1 + 0x138);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (plVar15 != (longlong *)0x0) {
      *plVar15 = *plVar15 + 1;
    }
    pcVar18 = DAT_23ed6a4f8;
    apcStack_88[0] = pcVar16;
    if (pcVar16 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar16 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar16;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar18 + 0x10) = 0;
      *(longlong **)(pcVar18 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x2cffffffff;
      pcStack_120 = _PyRuntime_exref;
      lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = *(longlong *)(pcVar18 + -8);
      plVar12 = *(longlong **)(lVar14 + 8);
      *plVar12 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar14;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
      *(code **)(lVar14 + 8) = pcVar18 + -0x10;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar18 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar21 = *(code **)DAT_23ed6a4f8;
        *(undefined8 *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar21;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar18 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      *(longlong *)(pcVar18 + 0x20) = 0x2cffffffff;
      pcStack_120 = _PyRuntime_exref;
      lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
      lVar3 = *(longlong *)(pcVar18 + -8);
      plVar12 = *(longlong **)(lVar14 + 8);
      *plVar12 = (longlong)(pcVar18 + -0x10);
      *(longlong *)(pcVar18 + -0x10) = lVar14;
      *(ulonglong *)(pcVar18 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar12;
      *(code **)(lVar14 + 8) = pcVar18 + -0x10;
      *(code **)(pcVar18 + 0x10) = pcVar16;
      *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
      }
    }
    pcVar16 = _Py_NoneStruct_exref;
    apcStack_88[0] = pcVar18;
    if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    plVar12 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (apcStack_88[0] == pcVar16) {
      pcVar18 = (code *)0x0;
    }
    else {
      pcVar18 = apcStack_88[0];
      if (apcStack_88[0] != (code *)0x0) {
        *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar18;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    plVar12 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
      (**(code **)(plVar12[1] + 0x30))();
    }
    *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
    if (*(longlong *)auStack_98._0_8_ == 0) {
      (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
    }
    if ((apcStack_88[0] != (code *)0x0) &&
       (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
       *(longlong *)apcStack_88[0] == 0)) {
      (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
    }
    apcStack_88[0] = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    iVar10 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                           *(undefined8 *)PyExc_Exception_exref);
    if (iVar10 != 0) {
      plVar12 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar15;
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))();
      }
      goto LAB_23e12e24d;
    }
    pcStack_110 = *(code **)(param_1 + 0x138);
    pcVar18 = (code *)0x0;
    if ((pcStack_110 == (code *)0x0) || (pcStack_110 == pcVar16)) {
      plVar12 = *(longlong **)PyExc_RuntimeError_exref;
      pcStack_110 = (code *)PyUnicode_FromString("No active exception to reraise");
      plVar17 = *(longlong **)(param_1 + 0x138);
      *plVar12 = *plVar12 + 1;
      *(longlong **)(param_1 + 0x138) = plVar15;
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        (**(code **)(plVar17[1] + 0x30))();
      }
      iVar10 = 0x2b;
    }
    else {
      plVar12 = *(longlong **)(pcStack_110 + 8);
      pcVar16 = *(code **)(pcStack_110 + 0x28);
      *(longlong *)pcStack_110 = *(longlong *)pcStack_110 + 1;
      *plVar12 = *plVar12 + 1;
      if (pcVar16 != (code *)0x0) {
        *(longlong *)pcVar16 = *(longlong *)pcVar16 + 1;
        if (plVar4 == *(longlong **)(pcVar16 + 0x18)) {
          *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar16 + 0x24);
        }
        *(longlong **)(param_1 + 0x138) = plVar15;
        lVar14 = *(longlong *)pcStack_110;
        *(longlong *)pcStack_110 = lVar14 + -1;
        if (lVar14 + -1 == 0) {
          (*(code *)plVar12[6])(pcStack_110);
          iVar10 = 0;
LAB_23e12ee89:
          if (*(longlong **)(pcVar16 + 0x18) == plVar4) goto LAB_23e12e7b0;
          pcVar21 = pcVar16;
          if (iVar10 != 0) goto LAB_23e12e714;
        }
        else if (plVar4 == *(longlong **)(pcVar16 + 0x18)) goto LAB_23e12e7b0;
        iVar10 = (int)plVar4[5];
        pcVar21 = pcVar16;
        goto LAB_23e12e714;
      }
      lVar14 = *(longlong *)pcStack_110;
      *(longlong **)(param_1 + 0x138) = plVar15;
      *(longlong *)pcStack_110 = lVar14 + -1;
      if (lVar14 + -1 == 0) {
        (*(code *)plVar12[6])();
        pcVar18 = (code *)0x0;
      }
      else {
        pcVar18 = (code *)0x0;
      }
LAB_23e12f21b:
      iVar10 = (int)plVar4[5];
    }
  }
LAB_23e12eef0:
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar16 + 0x10) = 0;
  *(longlong **)(pcVar16 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  *(int *)(pcVar16 + 0x24) = iVar10;
  lVar14 = *(longlong *)(pcStack_120 + 0x1f8);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
  lVar3 = *(longlong *)(pcVar16 + -8);
  plVar15 = *(longlong **)(lVar14 + 8);
  *plVar15 = (longlong)(pcVar16 + -0x10);
  *(longlong *)(pcVar16 + -0x10) = lVar14;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar3 & 3) | (ulonglong)plVar15;
  *(code **)(lVar14 + 8) = pcVar16 + -0x10;
LAB_23e12e7b0:
  FUN_23e8bba40(plVar4,&DAT_23ec5a149,plVar1,plVar2,pcVar18,0);
  if (_DAT_23eeaadd0 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeaadd0 = (longlong *)0x0;
  }
  lVar14 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar14 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
  plVar15 = (longlong *)plVar4[2];
  *(undefined4 *)(plVar4 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar4[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar4 = *plVar4 + -1;
  if (*plVar4 == 0) {
    (**(code **)(plVar4[1] + 0x30))(plVar4);
  }
  plVar4[0xf] = 0;
  if ((pcVar18 != (code *)0x0) &&
     (*(longlong *)pcVar18 = *(longlong *)pcVar18 + -1, *(longlong *)pcVar18 == 0)) {
    (**(code **)(*(longlong *)(pcVar18 + 8) + 0x30))(pcVar18);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,plVar12,pcStack_110,pcVar16);
  return (code *)0x0;
LAB_23e12fa03:
  uVar22 = 0x43;
  pcStack_120 = _PyRuntime_exref;
  goto LAB_23e12e93f;
}
