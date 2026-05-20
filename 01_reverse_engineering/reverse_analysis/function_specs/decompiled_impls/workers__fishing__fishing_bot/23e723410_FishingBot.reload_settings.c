/* ===== 23e723410 workers.fishing.fishing_bot:FishingBot.reload_settings ===== */
/* ghidra_name=FUN_23e723410 entry=23e723410 size=2841 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e723410(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  char cVar8;
  int iVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  longlong *plVar13;
  undefined4 uVar14;
  undefined8 uStack_68;
  undefined8 uStack_60;
  longlong *plStack_58;
  
  plVar10 = _DAT_23eedae80;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23eedae80 == (longlong *)0x0) {
LAB_23e72344a:
    _DAT_23eedae80 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaec8,DAT_23eedaeb8,8);
  }
  else {
    lVar12 = *_DAT_23eedae80;
    if (1 < lVar12) {
      *_DAT_23eedae80 = lVar12 + -1;
      goto LAB_23e72344a;
    }
    if (_DAT_23eedae80[2] != 0) {
      *_DAT_23eedae80 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e72344a;
    }
  }
  plVar3 = _DAT_23eedae80;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eedae80 + 9;
  lVar2 = *(longlong *)(lVar12 + 8);
  _DAT_23eedae80[0xf] = lVar2;
  *(longlong **)(lVar12 + 8) = plVar10;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  lVar12 = _DAT_23eed8cc0;
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  uVar5 = DAT_23eed8b40;
  *(undefined4 *)(plVar3 + 5) = 0xe8;
  plVar10 = (longlong *)FUN_23e915840(param_1,plVar1,uVar5,*(undefined8 *)(lVar12 + 0x18));
  if (plVar10 == (longlong *)0x0) {
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    uVar14 = 0xe8;
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e7237f5;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  pcVar7 = _Py_FalseStruct_exref;
  cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8b00,_Py_FalseStruct_exref);
  if (cVar8 == '\0') {
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar14 = 0xe9;
    uVar5 = *(undefined8 *)(param_1 + 0x60);
    uVar6 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e7237f5;
  }
  plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed89b0);
  if (plVar10 != (longlong *)0x0) {
    *(undefined4 *)(plVar3 + 5) = 0xec;
    plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8cc8);
    *plVar10 = *plVar10 + -1;
    if (*plVar10 == 0) {
      (**(code **)(plVar10[1] + 0x30))(plVar10);
    }
    if (plVar11 != (longlong *)0x0) {
      *plVar11 = *plVar11 + -1;
      if (*plVar11 == 0) {
        (**(code **)(plVar11[1] + 0x30))(plVar11);
      }
      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8980,pcVar7);
      if (cVar8 == '\0') {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xed;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = DAT_23ed6a4f8;
        goto joined_r0x00023e7237f5;
      }
      iVar9 = FUN_23e8be270(param_1,plVar1,DAT_23eed8a08);
      if (iVar9 == -1) {
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xf0;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = DAT_23ed6a4f8;
        goto joined_r0x00023e7237f5;
      }
      if (iVar9 != 0) {
        plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a08);
        if (plVar10 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0xf1;
          plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8cc8);
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          if (plVar11 != (longlong *)0x0) {
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              (**(code **)(plVar11[1] + 0x30))(plVar11);
            }
            goto LAB_23e7235c8;
          }
        }
        uVar5 = *(undefined8 *)(param_1 + 0x60);
        uVar6 = *(undefined8 *)(param_1 + 0x68);
        uVar14 = 0xf1;
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        plVar11 = DAT_23ed6a4f8;
        goto joined_r0x00023e7237f5;
      }
LAB_23e7235c8:
      iVar9 = FUN_23e8be270(param_1,plVar1,DAT_23eed8a00);
      if (iVar9 != -1) {
        if (iVar9 == 0) goto LAB_23e7235eb;
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a00);
        if (plVar13 != (longlong *)0x0) {
          iVar9 = FUN_23a35f020(plVar13);
          lVar12 = *plVar13 + -1;
          if (iVar9 == -1) {
            uVar5 = *(undefined8 *)(param_1 + 0x60);
            uVar6 = *(undefined8 *)(param_1 + 0x68);
            uVar14 = 0xf4;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *plVar13 = lVar12;
            plVar11 = DAT_23ed6a4f8;
            if (lVar12 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              plVar11 = DAT_23ed6a4f8;
            }
            goto joined_r0x00023e7237f5;
          }
          *plVar13 = lVar12;
          if (lVar12 == 0) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if (iVar9 == 0) {
LAB_23e7235eb:
            iVar9 = FUN_23e8be270(param_1,plVar1,DAT_23eed8af8);
            if (iVar9 == -1) {
              uVar5 = *(undefined8 *)(param_1 + 0x60);
              uVar6 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0xf8;
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar11 = DAT_23ed6a4f8;
              goto joined_r0x00023e7237f5;
            }
            if (iVar9 != 0) {
              plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8af8);
              if (plVar10 != (longlong *)0x0) {
                *(undefined4 *)(plVar3 + 5) = 0xf9;
                plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8cf0);
                *plVar10 = *plVar10 + -1;
                if (*plVar10 == 0) {
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                }
                if (plVar11 != (longlong *)0x0) {
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  goto LAB_23e72360e;
                }
              }
              uVar5 = *(undefined8 *)(param_1 + 0x60);
              uVar6 = *(undefined8 *)(param_1 + 0x68);
              uVar14 = 0xf9;
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              plVar11 = DAT_23ed6a4f8;
              goto joined_r0x00023e7237f5;
            }
LAB_23e72360e:
            plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a98);
            if (plVar10 != (longlong *)0x0) {
              *(undefined4 *)(plVar3 + 5) = 0xfc;
              plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8cf8);
              *plVar10 = *plVar10 + -1;
              if (*plVar10 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (plVar11 != (longlong *)0x0) {
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                lVar12 = FUN_23e8e0e20();
                if (lVar12 == 0) {
                  uVar14 = 0xff;
                  FUN_23e915740(param_1,&uStack_68,DAT_23eed8988);
                  plVar10 = plStack_58;
                  uVar5 = uStack_68;
                  uVar6 = uStack_60;
                  plVar11 = DAT_23ed6a4f8;
                }
                else {
                  plVar10 = (longlong *)FUN_23e8bc2f0(lVar12,_DAT_23eed8d00);
                  if (plVar10 != (longlong *)0x0) {
                    cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8998,plVar10);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (cVar8 != '\0') {
                      cVar8 = FUN_23e8d9ac0(plVar1,DAT_23eed8b38,pcVar7);
                      lVar12 = _DAT_23eed8d08;
                      if (cVar8 == '\0') {
                        uVar5 = *(undefined8 *)(param_1 + 0x60);
                        uVar14 = 0x100;
                        plVar10 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar6 = *(undefined8 *)(param_1 + 0x68);
                        plVar11 = DAT_23ed6a4f8;
                      }
                      else {
                        *(undefined4 *)(plVar3 + 5) = 0x102;
                        plVar10 = (longlong *)
                                  FUN_23e915840(param_1,plVar1,DAT_23eed8b40,
                                                *(undefined8 *)(lVar12 + 0x18));
                        if (plVar10 != (longlong *)0x0) {
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                          plVar10 = *(longlong **)(lVar12 + 0x28);
                          plVar3 = (longlong *)plVar10[2];
                          *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                               *(undefined8 *)(lVar12 + 0x30);
                          *(undefined4 *)(plVar10 + 8) = 0xffffffff;
                          if (plVar3 != (longlong *)0x0) {
                            plVar10[2] = 0;
                            *plVar3 = *plVar3 + -1;
                            if (*plVar3 == 0) {
                              (**(code **)(plVar3[1] + 0x30))();
                            }
                          }
                          *plVar10 = *plVar10 + -1;
                          if (*plVar10 == 0) {
                            (**(code **)(plVar10[1] + 0x30))(plVar10);
                          }
                          plVar10[0xf] = 0;
                          pcVar7 = _Py_NoneStruct_exref;
                          *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                          *plVar1 = *plVar1 + -1;
                          if (*plVar1 != 0) {
                            return pcVar7;
                          }
                          (**(code **)(plVar1[1] + 0x30))(plVar1);
                          return pcVar7;
                        }
                        uVar5 = *(undefined8 *)(param_1 + 0x60);
                        uVar14 = 0x102;
                        plVar10 = *(longlong **)(param_1 + 0x70);
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        uVar6 = *(undefined8 *)(param_1 + 0x68);
                        plVar11 = DAT_23ed6a4f8;
                      }
                      goto joined_r0x00023e7237f5;
                    }
                  }
                  uVar5 = *(undefined8 *)(param_1 + 0x60);
                  uVar14 = 0xff;
                  plVar10 = *(longlong **)(param_1 + 0x70);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uVar6 = *(undefined8 *)(param_1 + 0x68);
                  plVar11 = DAT_23ed6a4f8;
                }
                goto joined_r0x00023e7237f5;
              }
            }
            uVar5 = *(undefined8 *)(param_1 + 0x60);
            uVar6 = *(undefined8 *)(param_1 + 0x68);
            uVar14 = 0xfc;
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            plVar11 = DAT_23ed6a4f8;
            goto joined_r0x00023e7237f5;
          }
          plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a00);
          if (plVar10 != (longlong *)0x0) {
            *(undefined4 *)(plVar3 + 5) = 0xf4;
            plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23eed8cd0);
            *plVar10 = *plVar10 + -1;
            if (*plVar10 == 0) {
              (**(code **)(plVar10[1] + 0x30))(plVar10);
            }
            if (plVar11 != (longlong *)0x0) {
              iVar9 = FUN_23a35f020(plVar11);
              lVar12 = *plVar11 + -1;
              if (iVar9 == -1) {
                uVar5 = *(undefined8 *)(param_1 + 0x60);
                uVar6 = *(undefined8 *)(param_1 + 0x68);
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *plVar11 = lVar12;
                if (lVar12 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                uVar14 = 0xf4;
                plVar11 = DAT_23ed6a4f8;
                goto joined_r0x00023e7237f5;
              }
              *plVar11 = lVar12;
              if (lVar12 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              if (iVar9 == 1) {
                plVar10 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8a00);
                if (plVar10 != (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23eed8cd8);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  lVar12 = DAT_23eed8ce0;
                  if (plVar11 != (longlong *)0x0) {
                    *(undefined4 *)(plVar3 + 5) = 0xf5;
                    plVar10 = (longlong *)FUN_23e9186b0(param_1,plVar11,lVar12 + 0x18,DAT_23eed8ce8)
                    ;
                    *plVar11 = *plVar11 + -1;
                    if (*plVar11 == 0) {
                      (**(code **)(plVar11[1] + 0x30))(plVar11);
                    }
                    if (plVar10 != (longlong *)0x0) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      goto LAB_23e7235eb;
                    }
                  }
                }
                uVar5 = *(undefined8 *)(param_1 + 0x60);
                uVar6 = *(undefined8 *)(param_1 + 0x68);
                uVar14 = 0xf5;
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *(undefined8 *)(param_1 + 0x70) = 0;
                plVar11 = DAT_23ed6a4f8;
                goto joined_r0x00023e7237f5;
              }
              goto LAB_23e7235eb;
            }
          }
        }
      }
      uVar5 = *(undefined8 *)(param_1 + 0x60);
      uVar6 = *(undefined8 *)(param_1 + 0x68);
      uVar14 = 0xf4;
      plVar10 = *(longlong **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      plVar11 = DAT_23ed6a4f8;
      goto joined_r0x00023e7237f5;
    }
  }
  plVar10 = *(longlong **)(param_1 + 0x70);
  uVar5 = *(undefined8 *)(param_1 + 0x60);
  *(undefined8 *)(param_1 + 0x70) = 0;
  uVar14 = 0xec;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  uVar6 = *(undefined8 *)(param_1 + 0x68);
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e7237f5:
  DAT_23ed6a4f8 = plVar11;
  if (plVar10 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      plVar13 = plVar11;
    }
    pcVar7 = _PyRuntime_exref;
    plVar13[2] = 0;
    plVar13[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar12 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)(plVar13 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar2 = plVar13[-1];
    puVar4 = *(undefined8 **)(lVar12 + 8);
    *puVar4 = plVar13 + -2;
    plVar13[-2] = lVar12;
    plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
    *(longlong **)(lVar12 + 8) = plVar13 + -2;
  }
  else {
    plVar13 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (plVar11 == (longlong *)0x0) {
        plVar13 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        DAT_23ed6a4f8 = (longlong *)*plVar11;
        *plVar11 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        plVar13 = plVar11;
      }
      pcVar7 = _PyRuntime_exref;
      plVar13[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      lVar12 = *(longlong *)(pcVar7 + 0x1f8);
      *(undefined4 *)((longlong)plVar13 + 0x24) = uVar14;
      *(undefined4 *)(plVar13 + 4) = 0xffffffff;
      lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
      lVar2 = plVar13[-1];
      puVar4 = *(undefined8 **)(lVar12 + 8);
      *puVar4 = plVar13 + -2;
      plVar13[-2] = lVar12;
      plVar13[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
      lVar2 = *plVar10;
      *(longlong **)(lVar12 + 8) = plVar13 + -2;
      plVar13[2] = (longlong)plVar10;
      if (lVar2 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,&DAT_23ec5dc90,plVar1);
  if (_DAT_23eedae80 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedae80 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar12 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar10 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar10[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar10[0xf] = 0;
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,uVar5,uVar6,plVar13);
  return (code *)0x0;
}
