/* ===== 23e77e960 workers.fishing.fishing_bot:FishingBot._log ===== */
/* ghidra_name=FUN_23e77e960 entry=23e77e960 size=2470 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e77e960(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *******ppppppplVar2;
  longlong *plVar3;
  code *pcVar4;
  int iVar5;
  longlong lVar6;
  longlong *******ppppppplVar7;
  longlong lVar8;
  longlong *plVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  undefined4 uVar14;
  longlong *******ppppppplVar15;
  undefined8 *puVar16;
  longlong *******ppppppplStack_90;
  undefined8 uStack_88;
  longlong *******ppppppplStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar9 = _DAT_23eedad18;
  plVar1 = (longlong *)*param_3;
  ppppppplVar2 = (longlong *******)param_3[1];
  if (_DAT_23eedad18 == (longlong *)0x0) {
LAB_23e77e9a6:
    _DAT_23eedad18 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedaf28,DAT_23eedaeb8,0x20);
  }
  else {
    lVar8 = *_DAT_23eedad18;
    if (1 < lVar8) {
      *_DAT_23eedad18 = lVar8 + -1;
      goto LAB_23e77e9a6;
    }
    if (_DAT_23eedad18[2] != 0) {
      *_DAT_23eedad18 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e77e9a6;
    }
  }
  plVar3 = _DAT_23eedad18;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eedad18 + 9;
  lVar6 = *(longlong *)(lVar8 + 8);
  _DAT_23eedad18[0xf] = lVar6;
  *(longlong **)(lVar8 + 8) = plVar9;
  if ((lVar6 != 0) &&
     (((*(char *)(lVar6 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar6 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar6 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar6 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar6 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar6 = FUN_23e8e0ba0();
  lVar8 = _DAT_23eed97d0;
  uVar10 = _DAT_23eed97c8;
  if (lVar6 == 0) {
    plVar13 = (longlong *)0x0;
    FUN_23e915740(param_1,&ppppppplStack_78,DAT_23eed8c70);
    uVar14 = 0x64f;
    ppppppplVar7 = (longlong *******)0x0;
    plVar9 = plStack_68;
    plVar12 = DAT_23ed6a4f8;
    ppppppplStack_90 = ppppppplStack_78;
    uStack_88 = uStack_70;
joined_r0x00023e77ed9b:
    DAT_23ed6a4f8 = plVar12;
    if (plVar9 != (longlong *)0x0) {
      plVar11 = plVar9;
      if ((longlong *)plVar9[3] != plVar3) {
        if (plVar12 == (longlong *)0x0) {
          plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
        }
        else {
          DAT_23ed6a4f8 = (longlong *)*plVar12;
          *plVar12 = 1;
          DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          plVar11 = plVar12;
        }
        pcVar4 = _PyRuntime_exref;
        plVar11[3] = (longlong)plVar3;
        *plVar3 = *plVar3 + 1;
        lVar8 = *(longlong *)(pcVar4 + 0x1f8);
        *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
        *(undefined4 *)(plVar11 + 4) = 0xffffffff;
        lVar8 = *(longlong *)(*(longlong *)(lVar8 + 0x10) + 0x2e8);
        lVar6 = plVar11[-1];
        puVar16 = *(undefined8 **)(lVar8 + 8);
        *puVar16 = plVar11 + -2;
        plVar11[-2] = lVar8;
        plVar11[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar16;
        lVar6 = *plVar9;
        *(longlong **)(lVar8 + 8) = plVar11 + -2;
        plVar11[2] = (longlong)plVar9;
        if (lVar6 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      goto LAB_23e77ee46;
    }
    if (plVar12 == (longlong *)0x0) goto LAB_23e77f328;
    DAT_23ed6a4f8 = (longlong *)*plVar12;
    *plVar12 = 1;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    plVar11 = plVar12;
  }
  else {
    *(undefined4 *)(plVar3 + 5) = 0x64f;
    ppppppplVar7 = (longlong *******)
                   FUN_23e915840(param_1,lVar6,uVar10,*(undefined8 *)(lVar8 + 0x18));
    plVar9 = _DAT_23eed97d8;
    if (ppppppplVar7 == (longlong *******)0x0) {
      ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
      plVar9 = *(longlong **)(param_1 + 0x70);
      plVar13 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar14 = 0x64f;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e77ed9b;
    }
    lVar8 = *(longlong *)(param_1 + 0x10);
    plVar12 = *(longlong **)(lVar8 + 0xe30);
    if (plVar12 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
    }
    else {
      lVar6 = plVar12[3];
      *(int *)(lVar8 + 0xec4) = *(int *)(lVar8 + 0xec4) + -1;
      *(longlong *)(lVar8 + 0xe30) = lVar6;
      *plVar12 = 1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar12[6] = 0;
    *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
    lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar4 + 0x1f8) + 0x10) + 0x2e8);
    lVar6 = plVar12[-1];
    puVar16 = *(undefined8 **)(lVar8 + 8);
    *puVar16 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar16;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    *plVar9 = *plVar9 + 1;
    plVar12[3] = (longlong)plVar9;
    uVar10 = DAT_23ed6cd28;
    plVar13 = (longlong *)&DAT_23ed6a4c0;
    if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e77eb21:
      ppppppplStack_90 = (longlong *******)&ppppppplStack_78;
      uStack_70 = uVar10;
      ppppppplVar15 = ppppppplStack_90;
      ppppppplStack_78 = ppppppplVar7;
      lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0);
      uVar14 = SUB84(ppppppplVar15,0);
      if (lVar8 != 0) {
        plVar12[4] = lVar8;
        plVar11 = _DAT_23eed97e0;
        plVar9 = DAT_23ed6a4c0;
        *_DAT_23eed97e0 = *_DAT_23eed97e0 + 1;
        plVar12[5] = (longlong)plVar11;
        uVar10 = DAT_23ed6cd28;
        if (plVar9 == (longlong *)0x0) {
          plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar9 == (longlong *)0x0) goto LAB_23e77f310;
          *plVar9 = *plVar9 + 1;
          DAT_23ed6a4c0 = plVar9;
        }
        uStack_70 = uVar10;
        ppppppplStack_78 = ppppppplVar2;
        lVar8 = FUN_23e94ed00(param_1,plVar9,ppppppplStack_90);
        if (lVar8 != 0) {
          plVar12[6] = lVar8;
          plVar13 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          if (plVar13 == (longlong *)0x0) {
            ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uVar14 = 0x650;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_88 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar12 = DAT_23ed6a4f8;
          }
          else {
            lVar8 = FUN_23e8e0900();
            if (lVar8 == 0) {
              FUN_23e915740(param_1,ppppppplStack_90,DAT_23eed8e38);
              uVar14 = 0x651;
              plVar9 = plStack_68;
              plVar12 = DAT_23ed6a4f8;
              ppppppplStack_90 = ppppppplStack_78;
              uStack_88 = uStack_70;
            }
            else {
              *(undefined4 *)(plVar3 + 5) = 0x651;
              plVar9 = (longlong *)FUN_23e915840(param_1,lVar8,_DAT_23eed97e8,plVar13);
              if (plVar9 == (longlong *)0x0) {
                ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
                plVar9 = *(longlong **)(param_1 + 0x70);
                uVar14 = 0x651;
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_88 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar12 = DAT_23ed6a4f8;
              }
              else {
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                uVar10 = FUN_23a4450c0(DAT_23ed6cf28);
                *(undefined4 *)(plVar3 + 5) = 0x652;
                plVar9 = (longlong *)FUN_23e914090(param_1,uVar10,plVar13);
                if (plVar9 == (longlong *)0x0) {
                  ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  uVar14 = 0x652;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  uStack_88 = *(undefined8 *)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar12 = DAT_23ed6a4f8;
                }
                else {
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23eed8ac8);
                  if (plVar11 == (longlong *)0x0) {
                    ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar14 = 0x653;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar12 = DAT_23ed6a4f8;
                  }
                  else {
                    iVar5 = FUN_23a35f020(plVar11);
                    lVar8 = *plVar11 + -1;
                    if (iVar5 != -1) {
                      *plVar11 = lVar8;
                      if (lVar8 == 0) {
                        (**(code **)(plVar11[1] + 0x30))();
                      }
                      uVar10 = DAT_23eed8ac8;
                      if (iVar5 != 0) {
                        *(undefined4 *)(plVar3 + 5) = 0x655;
                        plVar9 = (longlong *)FUN_23e915840(param_1,plVar1,uVar10,plVar13);
                        if (plVar9 == (longlong *)0x0) {
                          plStack_68 = *(longlong **)(param_1 + 0x70);
                          ppppppplStack_78 = *(longlong ********)(param_1 + 0x60);
                          uStack_70 = *(undefined8 *)(param_1 + 0x68);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          FUN_23a35d6b0(ppppppplStack_90);
                        }
                        else {
                          *plVar9 = *plVar9 + -1;
                          if (*plVar9 == 0) {
                            (**(code **)(plVar9[1] + 0x30))(plVar9);
                          }
                        }
                      }
                      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar9 = *(longlong **)(lVar8 + 0x28);
                      plVar3 = (longlong *)plVar9[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar8 + 0x30);
                      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                      if (plVar3 != (longlong *)0x0) {
                        plVar9[2] = 0;
                        *plVar3 = *plVar3 + -1;
                        if (*plVar3 == 0) {
                          (**(code **)(plVar3[1] + 0x30))();
                        }
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      plVar9[0xf] = 0;
                      pcVar4 = _Py_NoneStruct_exref;
                      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
                      *ppppppplVar7 = (longlong ******)((longlong)*ppppppplVar7 + -1);
                      if (*ppppppplVar7 == (longlong ******)0x0) {
                        (*(code *)ppppppplVar7[1][6])(ppppppplVar7);
                      }
                      *plVar13 = *plVar13 + -1;
                      if (*plVar13 == 0) {
                        (**(code **)(plVar13[1] + 0x30))(plVar13);
                      }
                      *plVar1 = *plVar1 + -1;
                      if (*plVar1 == 0) {
                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                      }
                      *ppppppplVar2 = (longlong ******)((longlong)*ppppppplVar2 + -1);
                      if (*ppppppplVar2 != (longlong ******)0x0) {
                        return pcVar4;
                      }
                      (*(code *)ppppppplVar2[1][6])(ppppppplVar2);
                      return pcVar4;
                    }
                    ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar14 = 0x653;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uStack_88 = *(undefined8 *)(param_1 + 0x68);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar11 = lVar8;
                    plVar12 = DAT_23ed6a4f8;
                    if (lVar8 == 0) {
                      (**(code **)(plVar11[1] + 0x30))();
                      uVar14 = 0x653;
                      plVar12 = DAT_23ed6a4f8;
                    }
                  }
                }
              }
            }
          }
          goto joined_r0x00023e77ed9b;
        }
      }
      ppppppplStack_90 = *(longlong ********)(param_1 + 0x60);
      plVar9 = *(longlong **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_88 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      uVar14 = 0x650;
      plVar13 = (longlong *)0x0;
      plVar12 = DAT_23ed6a4f8;
      goto joined_r0x00023e77ed9b;
    }
    plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
    uVar14 = SUB84(puVar16,0);
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
      DAT_23ed6a4c0 = plVar9;
      goto LAB_23e77eb21;
    }
LAB_23e77f310:
    PyErr_PrintEx(0,0);
    Py_Exit(1);
LAB_23e77f328:
    plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  pcVar4 = _PyRuntime_exref;
  plVar11[2] = 0;
  plVar11[3] = (longlong)plVar3;
  *plVar3 = *plVar3 + 1;
  lVar8 = *(longlong *)(pcVar4 + 0x1f8);
  *(undefined4 *)((longlong)plVar11 + 0x24) = uVar14;
  lVar8 = *(longlong *)(lVar8 + 0x10);
  *(undefined4 *)(plVar11 + 4) = 0xffffffff;
  lVar8 = *(longlong *)(lVar8 + 0x2e8);
  lVar6 = plVar11[-1];
  puVar16 = *(undefined8 **)(lVar8 + 8);
  *puVar16 = plVar11 + -2;
  plVar11[-2] = lVar8;
  plVar11[-1] = (ulonglong)((uint)lVar6 & 3) | (ulonglong)puVar16;
  *(longlong **)(lVar8 + 8) = plVar11 + -2;
LAB_23e77ee46:
  FUN_23e8bba40(plVar3,&DAT_23ec5dee6,plVar1,ppppppplVar2,ppppppplVar7,plVar13);
  if (_DAT_23eedad18 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eedad18 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar8 + 0x28);
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
  plVar3 = (longlong *)plVar9[2];
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar3 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))();
    }
  }
  *plVar9 = *plVar9 + -1;
  if (*plVar9 == 0) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  plVar9[0xf] = 0;
  if ((ppppppplVar7 != (longlong *******)0x0) &&
     (*ppppppplVar7 = (longlong ******)((longlong)*ppppppplVar7 + -1),
     *ppppppplVar7 == (longlong ******)0x0)) {
    (*(code *)ppppppplVar7[1][6])(ppppppplVar7);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *ppppppplVar2 = (longlong ******)((longlong)*ppppppplVar2 + -1);
  if (*ppppppplVar2 == (longlong ******)0x0) {
    (*(code *)ppppppplVar2[1][6])(ppppppplVar2);
  }
  FUN_23a33aa70(param_1,ppppppplStack_90,uStack_88,plVar11);
  return (code *)0x0;
}
