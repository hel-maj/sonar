/* ===== 23e2de990 ui.hotkey_dialog:129 ===== */
/* ghidra_name=FUN_23e2de990 entry=23e2de990 size=5663 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2de990(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  longlong *plVar7;
  code *pcVar8;
  undefined8 uVar9;
  int iVar10;
  char cVar11;
  int iVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong lVar17;
  code *pcVar18;
  undefined8 uVar19;
  longlong *plVar20;
  code *pcVar21;
  code *pcVar22;
  undefined4 uVar23;
  code *pcVar24;
  code *pcStack_c0;
  code *pcStack_b8;
  code *pcStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  undefined8 uStack_78;
  longlong *plStack_70;
  code *pcStack_68;
  
  plVar14 = _DAT_23eeb0200;
  plVar2 = (longlong *)*param_3;
  plVar3 = (longlong *)param_3[1];
  if (_DAT_23eeb0200 == (longlong *)0x0) {
LAB_23e2de9d9:
    _DAT_23eeb0200 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eeb01f8,DAT_23eeb0268,0x18);
  }
  else {
    lVar13 = *_DAT_23eeb0200;
    if (1 < lVar13) {
      *_DAT_23eeb0200 = lVar13 + -1;
      goto LAB_23e2de9d9;
    }
    if (_DAT_23eeb0200[2] != 0) {
      *_DAT_23eeb0200 = lVar13 + -1;
      if (lVar13 + -1 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      goto LAB_23e2de9d9;
    }
  }
  plVar4 = _DAT_23eeb0200;
  lVar13 = *(longlong *)(param_1 + 0x38);
  plVar14 = _DAT_23eeb0200 + 9;
  lVar17 = *(longlong *)(lVar13 + 8);
  _DAT_23eeb0200[0xf] = lVar17;
  *(longlong **)(lVar13 + 8) = plVar14;
  if ((lVar17 != 0) &&
     (((*(char *)(lVar17 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar17 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar17 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar17 + 0x38))) && (plVar4[0xe] != 0)))) {
    plVar14 = *(longlong **)(lVar17 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar14;
    if (plVar14 != (longlong *)0x0) {
      *plVar14 = *plVar14 + 1;
    }
  }
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  lVar13 = FUN_23e8f5ff0();
  if (lVar13 == 0) {
    uVar23 = 0x85;
    FUN_23e915740(param_1,&uStack_78,_DAT_23eead598);
    pcVar22 = pcStack_68;
    uVar19 = uStack_78;
    plVar14 = plStack_70;
    goto LAB_23e2dee3f;
  }
  plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
  if (plVar14 != (longlong *)0x0) {
    plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead608);
    *plVar14 = *plVar14 + -1;
    if (*plVar14 == 0) {
      (**(code **)(plVar14[1] + 0x30))(plVar14);
    }
    if (plVar15 != (longlong *)0x0) {
      iVar12 = FUN_23e912620(plVar3,plVar15);
      *plVar15 = *plVar15 + -1;
      if (*plVar15 == 0) {
        (**(code **)(plVar15[1] + 0x30))(plVar15);
      }
      if (iVar12 != -1) {
        if (iVar12 == 1) {
          *(undefined4 *)(plVar4 + 5) = 0x87;
          plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eead610);
          if (plVar14 == (longlong *)0x0) {
            uVar19 = *(undefined8 *)(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x70);
            uVar23 = 0x87;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = *(longlong **)(param_1 + 0x68);
            goto LAB_23e2dee3f;
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          *(undefined4 *)(plVar4 + 5) = 0x88;
          plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar2,DAT_23eead588);
          if (plVar14 == (longlong *)0x0) {
            uVar19 = *(undefined8 *)(param_1 + 0x60);
            pcVar22 = *(code **)(param_1 + 0x70);
            uVar23 = 0x88;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar14 = *(longlong **)(param_1 + 0x68);
            goto LAB_23e2dee3f;
          }
LAB_23e2df974:
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))();
          }
LAB_23e2dedb0:
          pcVar22 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
          lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
          plVar14 = *(longlong **)(lVar13 + 0x28);
          plVar4 = (longlong *)plVar14[2];
          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
          *(undefined4 *)(plVar14 + 8) = 0xffffffff;
          if (plVar4 != (longlong *)0x0) {
            plVar14[2] = 0;
            *plVar4 = *plVar4 + -1;
            if (*plVar4 == 0) {
              (**(code **)(plVar4[1] + 0x30))();
            }
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          plVar14[0xf] = 0;
LAB_23e2df411:
          *plVar2 = *plVar2 + -1;
          if (*plVar2 == 0) {
            (**(code **)(plVar2[1] + 0x30))(plVar2);
          }
          *plVar3 = *plVar3 + -1;
          if (*plVar3 == 0) {
            (**(code **)(plVar3[1] + 0x30))(plVar3);
          }
          return pcVar22;
        }
        lVar13 = FUN_23e8f5ff0();
        if (lVar13 == 0) {
          uVar23 = 0x8b;
          FUN_23e915740(param_1,&uStack_78,_DAT_23eead598);
          pcVar22 = pcStack_68;
          uVar19 = uStack_78;
          plVar14 = plStack_70;
          goto LAB_23e2dee3f;
        }
        plVar14 = (longlong *)FUN_23e8bc2f0(lVar13,_DAT_23eead600);
        if (plVar14 != (longlong *)0x0) {
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead618);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 != (longlong *)0x0) {
            iVar12 = FUN_23e912620(plVar3,plVar15);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if (iVar12 != -1) {
              if (iVar12 == 1) {
                cVar11 = FUN_23e8d9ac0(plVar2,DAT_23eead3e8,DAT_23ed6cd28);
                if (cVar11 == '\0') {
                  uVar19 = *(undefined8 *)(param_1 + 0x60);
                  pcVar22 = *(code **)(param_1 + 0x70);
                  uVar23 = 0x8d;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar14 = *(longlong **)(param_1 + 0x68);
                  goto LAB_23e2dee3f;
                }
                *(undefined4 *)(plVar4 + 5) = 0x8e;
                plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eead610);
                if (plVar14 == (longlong *)0x0) {
                  uVar19 = *(undefined8 *)(param_1 + 0x60);
                  pcVar22 = *(code **)(param_1 + 0x70);
                  uVar23 = 0x8e;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar14 = *(longlong **)(param_1 + 0x68);
                  goto LAB_23e2dee3f;
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                *(undefined4 *)(plVar4 + 5) = 0x8f;
                plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eead620);
                if (plVar14 == (longlong *)0x0) {
                  uVar19 = *(undefined8 *)(param_1 + 0x60);
                  pcVar22 = *(code **)(param_1 + 0x70);
                  uVar23 = 0x8f;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar14 = *(longlong **)(param_1 + 0x68);
                  goto LAB_23e2dee3f;
                }
                goto LAB_23e2df974;
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eead3f0);
              if (plVar15 == (longlong *)0x0) {
                uVar19 = *(undefined8 *)(param_1 + 0x60);
                pcVar22 = *(code **)(param_1 + 0x70);
                uVar23 = 0x93;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar14 = *(longlong **)(param_1 + 0x68);
                goto LAB_23e2dee3f;
              }
              iVar12 = FUN_23a35f020(plVar15);
              lVar13 = *plVar15 + -1;
              if (iVar12 == -1) {
                uVar19 = *(undefined8 *)(param_1 + 0x60);
                plVar14 = *(longlong **)(param_1 + 0x68);
                pcVar22 = *(code **)(param_1 + 0x70);
                uVar23 = 0x93;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar15 = lVar13;
joined_r0x00023e2dfeb0:
                if (lVar13 == 0) {
                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                }
                goto LAB_23e2dee3f;
              }
              *plVar15 = lVar13;
              if (lVar13 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              if (iVar12 == 0) {
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eead3f0);
                if (plVar14 != (longlong *)0x0) {
                  iVar12 = PySequence_Contains(plVar14,plVar3);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  if (iVar12 != -1) {
                    pcVar22 = _Py_NoneStruct_exref;
                    if (iVar12 == 1) {
                      plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eead3f0);
                      if (plVar14 != (longlong *)0x0) {
                        plVar15 = (longlong *)FUN_23e8bc2f0(plVar14,_DAT_23eead648);
                        *plVar14 = *plVar14 + -1;
                        if (*plVar14 == 0) {
                          FUN_23a334bc0(plVar14);
                        }
                        if (plVar15 != (longlong *)0x0) {
                          *(undefined4 *)(plVar4 + 5) = 0x9d;
                          plVar14 = (longlong *)FUN_23e914090(param_1,plVar15,plVar3);
                          *plVar15 = *plVar15 + -1;
                          if (*plVar15 == 0) {
                            FUN_23a334bc0(plVar15);
                          }
                          if (plVar14 != (longlong *)0x0) {
                            *plVar14 = *plVar14 + -1;
                            pcVar22 = _Py_NoneStruct_exref;
                            if (*plVar14 == 0) {
                              FUN_23a334bc0(plVar14);
                              pcVar22 = _Py_NoneStruct_exref;
                            }
                            goto LAB_23e2df3c2;
                          }
                        }
                      }
                      uVar19 = *(undefined8 *)(param_1 + 0x60);
                      pcVar22 = *(code **)(param_1 + 0x70);
                      uVar23 = 0x9d;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      plVar14 = *(longlong **)(param_1 + 0x68);
                      goto LAB_23e2dee3f;
                    }
LAB_23e2df3c2:
                    lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                    plVar14 = *(longlong **)(lVar13 + 0x28);
                    plVar4 = (longlong *)plVar14[2];
                    *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                         *(undefined8 *)(lVar13 + 0x30);
                    *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                    if (plVar4 != (longlong *)0x0) {
                      plVar14[2] = 0;
                      *plVar4 = *plVar4 + -1;
                      if (*plVar4 == 0) {
                        (**(code **)(plVar4[1] + 0x30))();
                      }
                    }
                    *plVar14 = *plVar14 + -1;
                    if (*plVar14 == 0) {
                      (**(code **)(plVar14[1] + 0x30))(plVar14);
                    }
                    *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
                    plVar14[0xf] = 0;
                    goto LAB_23e2df411;
                  }
                }
                uVar19 = *(undefined8 *)(param_1 + 0x60);
                pcVar22 = *(code **)(param_1 + 0x70);
                uVar23 = 0x9c;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar14 = *(longlong **)(param_1 + 0x68);
                goto LAB_23e2dee3f;
              }
              plVar15 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eead628);
              if (plVar15 == (longlong *)0x0) goto LAB_23e2dfe5e;
              plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eead3f0);
              if (plVar14 == (longlong *)0x0) {
                uVar19 = *(undefined8 *)(param_1 + 0x60);
                plVar14 = *(longlong **)(param_1 + 0x68);
                pcVar22 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar23 = 0x94;
                *plVar15 = *plVar15 + -1;
                lVar13 = *plVar15;
                goto joined_r0x00023e2dfeb0;
              }
              *(undefined4 *)(plVar4 + 5) = 0x94;
              plVar16 = (longlong *)FUN_23e914090(param_1,plVar15,plVar14);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))(plVar15);
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                (**(code **)(plVar14[1] + 0x30))(plVar14);
              }
              if (plVar16 == (longlong *)0x0) goto LAB_23e2dfe5e;
              cVar11 = FUN_23e8d9ac0(plVar2,DAT_23eead3e8,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (cVar11 == '\0') goto LAB_23e2dfe5e;
              *(undefined4 *)(plVar4 + 5) = 0x95;
              plVar14 = (longlong *)FUN_23e91bfe0(param_1,plVar2,_DAT_23eead610);
              if (plVar14 == (longlong *)0x0) {
                uVar19 = *(undefined8 *)(param_1 + 0x60);
                pcVar22 = *(code **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                uVar23 = 0x95;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar14 = *(longlong **)(param_1 + 0x68);
                goto LAB_23e2dee3f;
              }
              *plVar14 = *plVar14 + -1;
              if (*plVar14 == 0) {
                FUN_23a334bc0(plVar14);
              }
              lVar13 = *(longlong *)(DAT_23eead8e0 + 0x20);
              if (*(char *)(lVar13 + 10) == '\0') {
                plVar14 = (longlong *)FUN_23a37a020(DAT_23eead8e0,_DAT_23eead630);
                if (plVar14 == (longlong *)0x0) goto LAB_23e2dff9d;
                lVar17 = *plVar14;
LAB_23e2dff94:
                if (lVar17 == 0) goto LAB_23e2dff9d;
              }
              else {
                iVar12 = *(int *)(lVar13 + 0xc);
                if (*(int *)(lVar13 + 0xc) == 0) {
                  *(int *)(lVar13 + 0xc) = DAT_23ec14e50;
                  iVar12 = DAT_23ec14e50;
                  DAT_23ec14e50 = DAT_23ec14e50 + 1;
                }
                if (_DAT_23ec14e44 != iVar12) {
                  _DAT_23ec14e44 = iVar12;
                  _DAT_23eeb01f0 =
                       FUN_23e8cbd60(lVar13,_DAT_23eead630,*(undefined8 *)(_DAT_23eead630 + 0x18));
                }
                if (-1 < _DAT_23eeb01f0) {
                  lVar1 = lVar13 + 0x20 + (1L << (*(byte *)(lVar13 + 9) & 0x3f));
                  lVar17 = *(longlong *)(lVar1 + 8 + _DAT_23eeb01f0 * 0x10);
                  if (lVar17 != 0) goto LAB_23e2ded0d;
                  _DAT_23eeb01f0 =
                       FUN_23e8cbd60(lVar13,_DAT_23eead630,*(undefined8 *)(_DAT_23eead630 + 0x18));
                  if (-1 < _DAT_23eeb01f0) {
                    lVar17 = *(longlong *)(lVar1 + 8 + _DAT_23eeb01f0 * 0x10);
                    goto LAB_23e2dff94;
                  }
                }
LAB_23e2dff9d:
                plVar14 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eead630);
                if ((plVar14 == (longlong *)0x0) || (lVar17 = *plVar14, lVar17 == 0)) {
                  uVar23 = 0x98;
                  FUN_23e915740(param_1,&uStack_78,_DAT_23eead630);
                  pcVar22 = pcStack_68;
                  uVar19 = uStack_78;
                  plVar14 = plStack_70;
                  goto LAB_23e2dee3f;
                }
              }
LAB_23e2ded0d:
              plVar15 = (longlong *)FUN_23e8bc2f0(lVar17,_DAT_23eead638);
              uVar19 = _DAT_23eead640;
              if (plVar15 != (longlong *)0x0) {
                plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,_DAT_23eead620);
                if (plVar14 == (longlong *)0x0) {
                  uVar19 = *(undefined8 *)(param_1 + 0x60);
                  plVar14 = *(longlong **)(param_1 + 0x68);
                  pcVar22 = *(code **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  uVar23 = 0x98;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    FUN_23a334bc0(plVar15);
                  }
                  goto LAB_23e2dee3f;
                }
                *(undefined4 *)(plVar4 + 5) = 0x98;
                uStack_78 = uVar19;
                plStack_70 = plVar14;
                plVar16 = (longlong *)FUN_23e94ed00(param_1,plVar15,&uStack_78);
                *plVar15 = *plVar15 + -1;
                if (*plVar15 == 0) {
                  FUN_23a334bc0(plVar15);
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  FUN_23a334bc0(plVar14);
                }
                if (plVar16 != (longlong *)0x0) {
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  goto LAB_23e2dedb0;
                }
              }
              uVar19 = *(undefined8 *)(param_1 + 0x60);
              pcVar22 = *(code **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              uVar23 = 0x98;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar14 = *(longlong **)(param_1 + 0x68);
              goto LAB_23e2dee3f;
            }
          }
        }
        uVar19 = *(undefined8 *)(param_1 + 0x60);
        pcVar22 = *(code **)(param_1 + 0x70);
        uVar23 = 0x8b;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar14 = *(longlong **)(param_1 + 0x68);
        goto LAB_23e2dee3f;
      }
    }
  }
  pcVar22 = *(code **)(param_1 + 0x70);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar23 = 0x85;
  uVar19 = *(undefined8 *)(param_1 + 0x60);
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar14 = *(longlong **)(param_1 + 0x68);
LAB_23e2dee3f:
  do {
    plVar15 = *(longlong **)(param_1 + 0x138);
    auStack_98._8_8_ = plVar14;
    auStack_98._0_8_ = uVar19;
    if (plVar15 != (longlong *)0x0) {
      *plVar15 = *plVar15 + 1;
    }
    pcVar21 = DAT_23ed6a4f8;
    apcStack_88[0] = pcVar22;
    if (pcVar22 == (code *)0x0) {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_c0 = _PyRuntime_exref;
      *(longlong *)(pcVar21 + 0x10) = 0;
      *(longlong **)(pcVar21 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar13 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar13 = *(longlong *)(lVar13 + 0x10);
      *(undefined4 *)(pcVar21 + 0x24) = uVar23;
      lVar13 = *(longlong *)(lVar13 + 0x2e8);
      lVar17 = *(longlong *)(pcVar21 + -8);
      puVar5 = *(undefined8 **)(lVar13 + 8);
      *puVar5 = pcVar21 + -0x10;
      *(longlong *)(pcVar21 + -0x10) = lVar13;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar5;
      *(code **)(lVar13 + 8) = pcVar21 + -0x10;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
      }
    }
    else {
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar18 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar18;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      pcStack_c0 = _PyRuntime_exref;
      *(longlong **)(pcVar21 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar13 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar13 = *(longlong *)(lVar13 + 0x10);
      *(undefined4 *)(pcVar21 + 0x24) = uVar23;
      lVar13 = *(longlong *)(lVar13 + 0x2e8);
      lVar17 = *(longlong *)(pcVar21 + -8);
      puVar5 = *(undefined8 **)(lVar13 + 8);
      *puVar5 = pcVar21 + -0x10;
      *(longlong *)(pcVar21 + -0x10) = lVar13;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar5;
      *(code **)(lVar13 + 8) = pcVar21 + -0x10;
      *(code **)(pcVar21 + 0x10) = pcVar22;
      *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
      if ((apcStack_88[0] != (code *)0x0) &&
         (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
         *(longlong *)apcStack_88[0] == 0)) {
        (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
      }
    }
    pcVar22 = _Py_NoneStruct_exref;
    apcStack_88[0] = pcVar21;
    if (((code *)auStack_98._0_8_ != _Py_NoneStruct_exref) &&
       ((code *)auStack_98._0_8_ != (code *)0x0)) {
      FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
    }
    plVar14 = *(longlong **)(auStack_98._8_8_ + 0x28);
    if (apcStack_88[0] == pcVar22) {
      pcVar21 = (code *)0x0;
    }
    else {
      pcVar21 = apcStack_88[0];
      if (apcStack_88[0] != (code *)0x0) {
        *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
      }
    }
    *(code **)(auStack_98._8_8_ + 0x28) = pcVar21;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
    }
    plVar14 = *(longlong **)(param_1 + 0x138);
    *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
    if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
      (**(code **)(plVar14[1] + 0x30))();
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
    pcVar24 = *(code **)(param_1 + 0x138);
    apcStack_88[0] = (code *)0x0;
    auStack_98 = (undefined1  [16])0x0;
    pcVar21 = *(code **)PyExc_Exception_exref;
    pcVar18 = *(code **)(pcVar24 + 8);
    if ((*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) & 0x4000000) == 0) {
      if (((int)*(uint *)(*(longlong *)(pcVar21 + 8) + 0xa8) < 0) &&
         (((byte)pcVar21[0xab] & 0x40) != 0)) {
        pcVar6 = *(code **)(pcVar18 + 8);
        if ((*(uint *)(pcVar6 + 0xa8) & 0x40000000) == 0) {
          pcVar8 = pcVar18;
          if (((int)*(uint *)(pcVar6 + 0xa8) < 0) && (((byte)pcVar18[0xab] & 0x40) != 0))
          goto LAB_23e2df131;
        }
        else {
          pcVar18 = pcVar6;
          pcVar8 = pcVar6;
          if (*(int *)(*(longlong *)(pcVar6 + 8) + 0xa8) < 0) {
LAB_23e2df131:
            lVar13 = *(longlong *)(pcVar18 + 0x158);
            if (lVar13 != 0) {
              if (*(longlong *)(lVar13 + 0x10) < 1) goto LAB_23e2df082;
              lVar17 = 0;
              while (pcVar21 != *(code **)(lVar13 + 0x18 + lVar17 * 8)) {
                lVar17 = lVar17 + 1;
                if (*(longlong *)(lVar13 + 0x10) == lVar17) goto LAB_23e2df082;
              }
              goto LAB_23e2df235;
            }
            do {
              if (pcVar21 == pcVar18) goto LAB_23e2df235;
              pcVar18 = *(code **)(pcVar18 + 0x100);
              pcVar8 = PyBaseObject_Type_exref;
            } while (pcVar18 != (code *)0x0);
          }
        }
        if (pcVar21 != pcVar8) goto LAB_23e2df082;
      }
      else {
        plVar16 = *(longlong **)PyExc_TypeError_exref;
        uVar19 = PyUnicode_FromString
                           ("catching classes that do not inherit from BaseException is not allowed"
                           );
        plVar20 = *(longlong **)(param_1 + 0x60);
        plVar7 = *(longlong **)(param_1 + 0x68);
        plVar14 = *(longlong **)(param_1 + 0x70);
        *(longlong **)(param_1 + 0x60) = plVar16;
        *plVar16 = *plVar16 + 1;
        *(undefined8 *)(param_1 + 0x68) = uVar19;
        *(undefined8 *)(param_1 + 0x70) = 0;
        if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
          (**(code **)(plVar20[1] + 0x30))();
        }
        if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
LAB_23e2df21f:
        if ((plVar14 == (longlong *)0x0) || (*plVar14 = *plVar14 + -1, *plVar14 != 0))
        goto LAB_23e2df22e;
        (**(code **)(plVar14[1] + 0x30))(plVar14);
        pcVar24 = *(code **)(param_1 + 0x138);
      }
    }
    else {
      lVar13 = *(longlong *)(pcVar21 + 0x10);
      if (lVar13 < 1) {
LAB_23e2df082:
        if ((pcVar24 == pcVar22) || (pcVar24 == (code *)0x0)) {
          plVar14 = *(longlong **)PyExc_RuntimeError_exref;
          pcStack_b8 = (code *)PyUnicode_FromString("No active exception to reraise");
          pcVar24 = *(code **)(param_1 + 0x138);
          *plVar14 = *plVar14 + 1;
          *(longlong **)(param_1 + 0x138) = plVar15;
          iVar12 = 0x83;
          if ((pcVar24 == (code *)0x0) ||
             (*(longlong *)pcVar24 = *(longlong *)pcVar24 + -1, iVar10 = 0x83,
             *(longlong *)pcVar24 != 0)) goto LAB_23e2df5e5;
LAB_23e2dfab5:
          iVar12 = iVar10;
          (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
          if (iVar12 != 0) goto LAB_23e2df5e5;
        }
        else {
          plVar14 = *(longlong **)(pcVar24 + 8);
          pcVar22 = *(code **)(pcVar24 + 0x28);
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
          *plVar14 = *plVar14 + 1;
          pcStack_b8 = pcVar24;
          if (pcVar22 != (code *)0x0) {
            *(longlong *)pcVar22 = *(longlong *)pcVar22 + 1;
            if (plVar4 == *(longlong **)(pcVar22 + 0x18)) {
              *(undefined4 *)(plVar4 + 5) = *(undefined4 *)(pcVar22 + 0x24);
            }
            *(longlong **)(param_1 + 0x138) = plVar15;
            *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
            if (*(longlong *)pcVar24 != 0) {
              pcVar21 = pcVar22;
              if (*(longlong **)(pcVar22 + 0x18) != plVar4) goto LAB_23e2df81e;
              goto LAB_23e2df670;
            }
            (*(code *)plVar14[6])(pcVar24);
            iVar12 = 0;
            goto LAB_23e2df807;
          }
          *(longlong **)(param_1 + 0x138) = plVar15;
          *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
          if (*(longlong *)pcVar24 == 0) {
            iVar10 = 0;
            goto LAB_23e2dfab5;
          }
        }
        iVar12 = (int)plVar4[5];
        goto LAB_23e2df5e5;
      }
      lVar17 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar21 + lVar17 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar21 + lVar17 * 8 + 0x18) + 0xab) & 0x40) == 0)) {
          plVar16 = *(longlong **)PyExc_TypeError_exref;
          uVar19 = PyUnicode_FromString
                             (
                             "catching classes that do not inherit from BaseException is not allowed"
                             );
          plVar20 = *(longlong **)(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x68);
          plVar14 = *(longlong **)(param_1 + 0x70);
          *(longlong **)(param_1 + 0x60) = plVar16;
          *plVar16 = *plVar16 + 1;
          *(undefined8 *)(param_1 + 0x68) = uVar19;
          *(undefined8 *)(param_1 + 0x70) = 0;
          if ((plVar20 != (longlong *)0x0) && (*plVar20 = *plVar20 + -1, *plVar20 == 0)) {
            (**(code **)(plVar20[1] + 0x30))();
          }
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          goto LAB_23e2df21f;
        }
        lVar17 = lVar17 + 1;
      } while (lVar13 != lVar17);
      lVar17 = 0;
      while (iVar12 = FUN_23a35ebd0(param_1,pcVar18,*(undefined8 *)(pcVar21 + lVar17 * 8 + 0x18)),
            iVar12 == 0) {
        lVar17 = lVar17 + 1;
        if (lVar13 == lVar17) {
          pcVar24 = *(code **)(param_1 + 0x138);
          goto LAB_23e2df082;
        }
      }
LAB_23e2df22e:
      pcVar24 = *(code **)(param_1 + 0x138);
    }
LAB_23e2df235:
    *(longlong *)pcVar24 = *(longlong *)pcVar24 + 1;
    uVar19 = FUN_23a3a0d40(DAT_23ed6cf28);
    plVar14 = _DAT_23eead650;
    lVar13 = *(longlong *)(param_1 + 0x10);
    plVar16 = *(longlong **)(lVar13 + 0xe20);
    if (plVar16 == (longlong *)0x0) {
      plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar17 = plVar16[3];
      *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
      *(longlong *)(lVar13 + 0xe20) = lVar17;
      *plVar16 = 1;
    }
    plVar16[4] = 0;
    lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(pcStack_c0 + 0x1f8) + 0x10) + 0x2e8);
    lVar17 = plVar16[-1];
    puVar5 = *(undefined8 **)(lVar13 + 8);
    *puVar5 = plVar16 + -2;
    plVar16[-2] = lVar13;
    plVar16[-1] = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar13 + 8) = plVar16 + -2;
    plVar20 = DAT_23ed6a4c0;
    *plVar14 = *plVar14 + 1;
    plVar16[3] = (longlong)plVar14;
    uVar9 = DAT_23ed6cd28;
    if (plVar20 != (longlong *)0x0) goto LAB_23e2df2f5;
    plVar20 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    if (plVar20 != (longlong *)0x0) break;
    PyErr_PrintEx(0);
    Py_Exit(1);
LAB_23e2dfe5e:
    uVar19 = *(undefined8 *)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x70);
    uVar23 = 0x94;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar14 = *(longlong **)(param_1 + 0x68);
  } while( true );
  *plVar20 = *plVar20 + 1;
  DAT_23ed6a4c0 = plVar20;
LAB_23e2df2f5:
  uStack_a0 = uVar9;
  pcStack_a8 = pcVar24;
  lVar13 = FUN_23e94ed00(param_1,plVar20,&pcStack_a8);
  if (lVar13 == 0) {
    pcStack_b8 = *(code **)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
  }
  else {
    plVar16[4] = lVar13;
    plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
    *plVar16 = *plVar16 + -1;
    if (*plVar16 == 0) {
      (**(code **)(plVar16[1] + 0x30))(plVar16);
    }
    if (plVar14 != (longlong *)0x0) {
      *(undefined4 *)(plVar4 + 5) = 0xa0;
      plVar16 = (longlong *)FUN_23e914090(param_1,uVar19,plVar14);
      *plVar14 = *plVar14 + -1;
      if (*plVar14 == 0) {
        (**(code **)(plVar14[1] + 0x30))(plVar14);
      }
      if (plVar16 == (longlong *)0x0) goto LAB_23e2df8f0;
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
      if (*(longlong *)pcVar24 == 0) {
        (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
      }
      plVar14 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar15;
      if ((plVar14 != (longlong *)0x0) && (*plVar14 = *plVar14 + -1, *plVar14 == 0)) {
        (**(code **)(plVar14[1] + 0x30))();
      }
      goto LAB_23e2df3c2;
    }
LAB_23e2df8f0:
    pcStack_b8 = *(code **)(param_1 + 0x68);
    plVar14 = *(longlong **)(param_1 + 0x60);
    pcVar22 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
  }
  *(longlong *)pcVar24 = *(longlong *)pcVar24 + -1;
  if (*(longlong *)pcVar24 == 0) {
    (**(code **)(*(longlong *)(pcVar24 + 8) + 0x30))(pcVar24);
  }
  plVar16 = *(longlong **)(param_1 + 0x138);
  *(longlong **)(param_1 + 0x138) = plVar15;
  if ((plVar16 == (longlong *)0x0) || (*plVar16 = *plVar16 + -1, *plVar16 != 0)) {
    if (pcVar22 == (code *)0x0) goto LAB_23e2dfce0;
    pcVar21 = pcVar22;
    if (plVar4 == *(longlong **)(pcVar22 + 0x18)) goto LAB_23e2df670;
    uVar23 = 0xa0;
  }
  else {
    (**(code **)(plVar16[1] + 0x30))();
    if (pcVar22 == (code *)0x0) {
LAB_23e2dfce0:
      iVar12 = 0xa0;
LAB_23e2df5e5:
      pcVar21 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar22 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar22;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong *)(pcVar21 + 0x10) = 0;
      *(longlong **)(pcVar21 + 0x18) = plVar4;
      *plVar4 = *plVar4 + 1;
      lVar13 = *(longlong *)(pcStack_c0 + 0x1f8);
      *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
      lVar13 = *(longlong *)(lVar13 + 0x10);
      *(int *)(pcVar21 + 0x24) = iVar12;
      lVar13 = *(longlong *)(lVar13 + 0x2e8);
      lVar17 = *(longlong *)(pcVar21 + -8);
      puVar5 = *(undefined8 **)(lVar13 + 8);
      *puVar5 = pcVar21 + -0x10;
      *(longlong *)(pcVar21 + -0x10) = lVar13;
      *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar5;
      *(code **)(lVar13 + 8) = pcVar21 + -0x10;
      goto LAB_23e2df670;
    }
    iVar12 = 0xa0;
LAB_23e2df807:
    pcVar21 = pcVar22;
    if (plVar4 == *(longlong **)(pcVar22 + 0x18)) goto LAB_23e2df670;
    uVar23 = 0xa0;
    if (iVar12 == 0) {
LAB_23e2df81e:
      uVar23 = (undefined4)plVar4[5];
    }
  }
  pcVar21 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar21 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar18 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar18;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar21 + 0x18) = plVar4;
  *plVar4 = *plVar4 + 1;
  lVar13 = *(longlong *)(pcStack_c0 + 0x1f8);
  *(undefined4 *)(pcVar21 + 0x20) = 0xffffffff;
  *(undefined4 *)(pcVar21 + 0x24) = uVar23;
  lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
  lVar17 = *(longlong *)(pcVar21 + -8);
  puVar5 = *(undefined8 **)(lVar13 + 8);
  *puVar5 = pcVar21 + -0x10;
  *(longlong *)(pcVar21 + -0x10) = lVar13;
  *(ulonglong *)(pcVar21 + -8) = (ulonglong)((uint)lVar17 & 3) | (ulonglong)puVar5;
  lVar17 = *(longlong *)pcVar22;
  *(code **)(lVar13 + 8) = pcVar21 + -0x10;
  *(code **)(pcVar21 + 0x10) = pcVar22;
  if (lVar17 == 0) {
    (**(code **)(*(longlong *)(pcVar22 + 8) + 0x30))(pcVar22);
  }
LAB_23e2df670:
  FUN_23e8bba40(plVar4,&DAT_23ec5b355,plVar2,plVar3,0);
  if (_DAT_23eeb0200 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    _DAT_23eeb0200 = (longlong *)0x0;
  }
  lVar13 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar4 = *(longlong **)(lVar13 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
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
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,plVar14,pcStack_b8,pcVar21);
  return (code *)0x0;
}
