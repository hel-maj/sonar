/* ===== 23e2b5580 ui.home_tab:? ===== */
/* ghidra_name=FUN_23e2b5580 entry=23e2b5580 size=2604 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2b5580(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong *plVar3;
  longlong lVar4;
  longlong *plVar5;
  undefined8 *puVar6;
  code *pcVar7;
  char cVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  undefined4 uVar13;
  code *pcVar14;
  code *pcStack_68;
  undefined8 uStack_60;
  longlong *aplStack_58 [3];
  
  plVar9 = _DAT_23eeb0388;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  plVar3 = (longlong *)param_3[2];
  aplStack_58[0] = (longlong *)0x0;
  pcStack_68 = (code *)0x0;
  uStack_60 = 0;
  if (_DAT_23eeb0388 == (longlong *)0x0) {
LAB_23e2b55d7:
    _DAT_23eeb0388 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0378,DAT_23eeb0380,0x20);
  }
  else {
    lVar11 = *_DAT_23eeb0388;
    if (1 < lVar11) {
      *_DAT_23eeb0388 = lVar11 + -1;
      goto LAB_23e2b55d7;
    }
    if (_DAT_23eeb0388[2] != 0) {
      *_DAT_23eeb0388 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e2b55d7;
    }
  }
  plVar5 = _DAT_23eeb0388;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eeb0388 + 9;
  lVar4 = *(longlong *)(lVar11 + 8);
  _DAT_23eeb0388[0xf] = lVar4;
  *(longlong **)(lVar11 + 8) = plVar9;
  if ((lVar4 != 0) &&
     (((*(char *)(lVar4 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar4 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar4 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar4 + 0x38))
       ) && (plVar5[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar4 + 0x28);
    *(longlong **)(plVar5[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar11 = *(longlong *)(param_2 + 0xd8);
  *plVar5 = *plVar5 + 1;
  *(undefined4 *)(plVar5 + 8) = 0;
  pcVar7 = _Py_NoneStruct_exref;
  lVar11 = *(longlong *)(lVar11 + 0x10);
  if (lVar11 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar11 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar11 = DAT_23ed6cd40 + 0x30;
    }
    uStack_60 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar11);
    pcStack_68 = *(code **)PyExc_NameError_exref;
    *(longlong *)pcStack_68 = *(longlong *)pcStack_68 + 1;
    aplStack_58[0] = (longlong *)0x0;
    if (pcStack_68 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&pcStack_68,&uStack_60,aplStack_58);
    }
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_60);
    uVar13 = 0x29;
    plVar9 = aplStack_58[0];
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023e2b5c4b;
  }
  pcVar14 = (code *)0x0;
  if (pcVar1 != _Py_NoneStruct_exref) {
    pcVar14 = pcVar1;
  }
  plVar9 = (longlong *)FUN_23e9543b0(param_1,DAT_23eeae258,lVar11,pcVar14);
  if (plVar9 != (longlong *)0x0) {
    *(undefined4 *)(plVar5 + 5) = 0x29;
    plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,DAT_23ed6cdb0,plVar3);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      cVar8 = FUN_23e8d9ac0(pcVar1,_DAT_23eead900,plVar2);
      if (cVar8 == '\0') {
        plVar9 = *(longlong **)(param_1 + 0x70);
        pcStack_68 = *(code **)(param_1 + 0x60);
        uStack_60 = *(undefined8 *)(param_1 + 0x68);
        uVar13 = 0x2a;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = DAT_23ed6a4f8;
      }
      else {
        *(undefined4 *)(plVar5 + 5) = 0x2b;
        plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eead908);
        if (plVar9 == (longlong *)0x0) {
          pcStack_68 = *(code **)(param_1 + 0x60);
          uStack_60 = *(undefined8 *)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x70);
          uVar13 = 0x2b;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar10 = DAT_23ed6a4f8;
        }
        else {
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          lVar11 = FUN_23e8f78c0();
          if (lVar11 == 0) {
            FUN_23e915740(param_1,&pcStack_68,DAT_23eead910);
            uVar13 = 0x2e;
            plVar9 = aplStack_58[0];
            plVar10 = DAT_23ed6a4f8;
          }
          else {
            *(undefined4 *)(plVar5 + 5) = 0x2e;
            plVar9 = (longlong *)FUN_23e91a870(param_1,lVar11);
            if (plVar9 != (longlong *)0x0) {
              cVar8 = FUN_23e8d9ac0(pcVar1,_DAT_23eead918,plVar9);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              if (cVar8 != '\0') {
                plVar9 = (longlong *)FUN_23e8bc2f0(pcVar1,_DAT_23eead918);
                if (plVar9 != (longlong *)0x0) {
                  plVar10 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead920);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar10 != (longlong *)0x0) {
                    plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,_DAT_23eead928);
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      (**(code **)(plVar10[1] + 0x30))(plVar10);
                    }
                    if (plVar12 != (longlong *)0x0) {
                      plVar9 = (longlong *)FUN_23e8bc2f0(pcVar1,DAT_23eead930);
                      if (plVar9 == (longlong *)0x0) {
                        pcStack_68 = *(code **)(param_1 + 0x60);
                        uStack_60 = *(undefined8 *)(param_1 + 0x68);
                        aplStack_58[0] = *(longlong **)(param_1 + 0x70);
                        uVar13 = 0x2f;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar12 = *plVar12 + -1;
                        plVar9 = aplStack_58[0];
                        plVar10 = DAT_23ed6a4f8;
                        if (*plVar12 == 0) {
                          (**(code **)(plVar12[1] + 0x30))(plVar12);
                          uVar13 = 0x2f;
                          plVar9 = aplStack_58[0];
                          plVar10 = DAT_23ed6a4f8;
                        }
                        goto joined_r0x00023e2b5c4b;
                      }
                      *(undefined4 *)(plVar5 + 5) = 0x2f;
                      plVar10 = (longlong *)FUN_23e914090(param_1,plVar12,plVar9);
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        (**(code **)(plVar12[1] + 0x30))(plVar12);
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      if (plVar10 != (longlong *)0x0) {
                        *plVar10 = *plVar10 + -1;
                        if (*plVar10 == 0) {
                          (**(code **)(plVar10[1] + 0x30))(plVar10);
                        }
                        plVar9 = (longlong *)FUN_23e8bc2f0(pcVar1,_DAT_23eead918);
                        lVar11 = _DAT_23eead940;
                        if (plVar9 != (longlong *)0x0) {
                          *(undefined4 *)(plVar5 + 5) = 0x30;
                          plVar10 = (longlong *)
                                    FUN_23e915840(param_1,plVar9,_DAT_23eead938,
                                                  *(undefined8 *)(lVar11 + 0x18));
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                          if (plVar10 != (longlong *)0x0) {
                            *plVar10 = *plVar10 + -1;
                            if (*plVar10 == 0) {
                              (**(code **)(plVar10[1] + 0x30))(plVar10);
                            }
                            *(undefined4 *)(plVar5 + 5) = 0x33;
                            plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eead930);
                            if (plVar9 == (longlong *)0x0) {
                              pcStack_68 = *(code **)(param_1 + 0x60);
                              uStack_60 = *(undefined8 *)(param_1 + 0x68);
                              plVar9 = *(longlong **)(param_1 + 0x70);
                              uVar13 = 0x33;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar10 = DAT_23ed6a4f8;
                            }
                            else {
                              *plVar9 = *plVar9 + -1;
                              if (*plVar9 == 0) {
                                (**(code **)(plVar9[1] + 0x30))(plVar9);
                              }
                              *(undefined4 *)(plVar5 + 5) = 0x34;
                              plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eead948);
                              if (plVar9 != (longlong *)0x0) {
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                                plVar9 = *(longlong **)(lVar11 + 0x28);
                                plVar5 = (longlong *)plVar9[2];
                                *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                                     *(undefined8 *)(lVar11 + 0x30);
                                *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                                if (plVar5 != (longlong *)0x0) {
                                  plVar9[2] = 0;
                                  *plVar5 = *plVar5 + -1;
                                  if (*plVar5 == 0) {
                                    (**(code **)(plVar5[1] + 0x30))();
                                  }
                                }
                                *plVar9 = *plVar9 + -1;
                                if (*plVar9 == 0) {
                                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                                }
                                *(longlong *)pcVar7 = *(longlong *)pcVar7 + 1;
                                plVar9[0xf] = 0;
                                *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
                                if (*(longlong *)pcVar1 == 0) {
                                  (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
                                }
                                *plVar2 = *plVar2 + -1;
                                if (*plVar2 == 0) {
                                  (**(code **)(plVar2[1] + 0x30))(plVar2);
                                }
                                *plVar3 = *plVar3 + -1;
                                if (*plVar3 != 0) {
                                  return pcVar7;
                                }
                                (**(code **)(plVar3[1] + 0x30))(plVar3);
                                return pcVar7;
                              }
                              pcStack_68 = *(code **)(param_1 + 0x60);
                              uStack_60 = *(undefined8 *)(param_1 + 0x68);
                              plVar9 = *(longlong **)(param_1 + 0x70);
                              uVar13 = 0x34;
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              plVar10 = DAT_23ed6a4f8;
                            }
                            goto joined_r0x00023e2b5c4b;
                          }
                        }
                        pcStack_68 = *(code **)(param_1 + 0x60);
                        uStack_60 = *(undefined8 *)(param_1 + 0x68);
                        plVar9 = *(longlong **)(param_1 + 0x70);
                        uVar13 = 0x30;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        plVar10 = DAT_23ed6a4f8;
                        goto joined_r0x00023e2b5c4b;
                      }
                    }
                  }
                }
                pcStack_68 = *(code **)(param_1 + 0x60);
                uStack_60 = *(undefined8 *)(param_1 + 0x68);
                plVar9 = *(longlong **)(param_1 + 0x70);
                uVar13 = 0x2f;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar10 = DAT_23ed6a4f8;
                goto joined_r0x00023e2b5c4b;
              }
            }
            pcStack_68 = *(code **)(param_1 + 0x60);
            uStack_60 = *(undefined8 *)(param_1 + 0x68);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uVar13 = 0x2e;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = DAT_23ed6a4f8;
          }
        }
      }
      goto joined_r0x00023e2b5c4b;
    }
  }
  pcStack_68 = *(code **)(param_1 + 0x60);
  uStack_60 = *(undefined8 *)(param_1 + 0x68);
  plVar9 = *(longlong **)(param_1 + 0x70);
  uVar13 = 0x29;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
joined_r0x00023e2b5c4b:
  DAT_23ed6a4f8 = plVar10;
  aplStack_58[0] = plVar9;
  if (plVar9 == (longlong *)0x0) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
    lVar11 = *(longlong *)(lVar11 + 0x10);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(lVar11 + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar11 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
    plVar9 = plVar10;
    if ((aplStack_58[0] != (longlong *)0x0) &&
       (*aplStack_58[0] = *aplStack_58[0] + -1, *aplStack_58[0] == 0)) {
      (**(code **)(aplStack_58[0][1] + 0x30))(aplStack_58[0]);
    }
  }
  else if ((longlong *)plVar9[3] != plVar5) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar7 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar5;
    *plVar5 = *plVar5 + 1;
    lVar11 = *(longlong *)(pcVar7 + 0x1f8);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar13;
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
    lVar4 = plVar10[-1];
    puVar6 = *(undefined8 **)(lVar11 + 8);
    *puVar6 = plVar10 + -2;
    plVar10[-2] = lVar11;
    plVar10[-1] = (ulonglong)((uint)lVar4 & 3) | (ulonglong)puVar6;
    *(longlong **)(lVar11 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar10;
    if ((aplStack_58[0] != (longlong *)0x0) &&
       (*aplStack_58[0] = *aplStack_58[0] + -1, *aplStack_58[0] == 0)) {
      (**(code **)(aplStack_58[0][1] + 0x30))();
    }
  }
  aplStack_58[0] = plVar9;
  FUN_23e8bba40(plVar5,&DAT_23ec5b378,pcVar1,plVar2,plVar3,*(undefined8 *)(param_2 + 0xd8));
  if (_DAT_23eeb0388 == plVar5) {
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))(plVar5);
    }
    _DAT_23eeb0388 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar11 + 0x28);
  plVar5 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar5 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar5 = *plVar5 + -1;
    if (*plVar5 == 0) {
      (**(code **)(plVar5[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
  if (*(longlong *)pcVar1 == 0) {
    (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  FUN_23a33aa70(param_1,pcStack_68,uStack_60,aplStack_58[0]);
  return (code *)0x0;
}
