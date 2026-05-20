/* ===== 23e316a60 ui.telegram_tab:c1016 ===== */
/* ghidra_name=forced_23e316a60 entry=23e316a60 size=2492 */

code * forced_23e316a60(longlong param_1,longlong param_2,undefined8 *param_3)

{
  code *pcVar1;
  longlong *plVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 *puVar5;
  code *pcVar6;
  char cVar7;
  int iVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong lVar12;
  code *pcVar13;
  undefined4 uVar14;
  code *pcStack_68;
  undefined8 uStack_60;
  longlong *aplStack_58 [3];
  
  plVar9 = DAT_23eeb4cf8;
  pcVar1 = (code *)*param_3;
  plVar2 = (longlong *)param_3[1];
  aplStack_58[0] = (longlong *)0x0;
  pcStack_68 = (code *)0x0;
  uStack_60 = 0;
  if (DAT_23eeb4cf8 == (longlong *)0x0) {
LAB_23e316ab3:
    DAT_23eeb4cf8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb4ce8,DAT_23eeb4cf0,0x18);
  }
  else {
    lVar12 = *DAT_23eeb4cf8;
    if (1 < lVar12) {
      *DAT_23eeb4cf8 = lVar12 + -1;
      goto LAB_23e316ab3;
    }
    if (DAT_23eeb4cf8[2] != 0) {
      *DAT_23eeb4cf8 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e316ab3;
    }
  }
  plVar4 = DAT_23eeb4cf8;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eeb4cf8 + 9;
  lVar3 = *(longlong *)(lVar12 + 8);
  DAT_23eeb4cf8[0xf] = lVar3;
  *(longlong **)(lVar12 + 8) = plVar9;
  if ((lVar3 != 0) &&
     (((*(char *)(lVar3 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar3 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar3 + 0x38))
       ) && (plVar4[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar3 + 0x28);
    *(longlong **)(plVar4[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  lVar12 = *(longlong *)(param_2 + 0xd8);
  *plVar4 = *plVar4 + 1;
  *(undefined4 *)(plVar4 + 8) = 0;
  pcVar6 = _Py_NoneStruct_exref;
  lVar12 = *(longlong *)(lVar12 + 0x10);
  if (lVar12 == 0) {
    if (((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x40) == 0) ||
       ((*(byte *)(DAT_23ed6cd40 + 0x20) & 0x20) == 0)) {
      lVar12 = *(longlong *)(DAT_23ed6cd40 + 0x38);
    }
    else {
      lVar12 = DAT_23ed6cd40 + 0x30;
    }
    uStack_60 = PyUnicode_FromFormat
                          ("cannot access free variable \'%s\' where it is not associated with a value in enclosing scope"
                           ,lVar12);
    pcStack_68 = *(code **)PyExc_NameError_exref;
    *(longlong *)pcStack_68 = *(longlong *)pcStack_68 + 1;
    aplStack_58[0] = (longlong *)0x0;
    if (pcStack_68 != _Py_NoneStruct_exref) {
      FUN_23e91b1b0(param_1,&pcStack_68,&uStack_60,aplStack_58);
    }
    uVar14 = 0x16;
    FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),uStack_60);
    plVar9 = aplStack_58[0];
    plVar10 = DAT_23ed6a4f8;
    goto joined_r0x00023e31709c;
  }
  pcVar13 = (code *)0x0;
  if (pcVar1 != _Py_NoneStruct_exref) {
    pcVar13 = pcVar1;
  }
  plVar9 = (longlong *)FUN_23e9543b0(param_1,DAT_23eeb3ee0,lVar12,pcVar13);
  if (plVar9 != (longlong *)0x0) {
    *(undefined4 *)(plVar4 + 5) = 0x16;
    plVar10 = (longlong *)FUN_23e91bfe0(param_1,plVar9,DAT_23ed6cdb0);
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      lVar12 = *(longlong *)(DAT_23eeb3ee0 + 0x20);
      if (*(char *)(lVar12 + 10) == '\0') {
        plVar9 = (longlong *)FUN_23a37a020(DAT_23eeb3ee0,DAT_23eeb3980);
        if (plVar9 == (longlong *)0x0) goto LAB_23e316e29;
        lVar12 = *plVar9;
LAB_23e317278:
        if (lVar12 == 0) goto LAB_23e316e29;
      }
      else {
        iVar8 = *(int *)(lVar12 + 0xc);
        if (*(int *)(lVar12 + 0xc) == 0) {
          *(int *)(lVar12 + 0xc) = DAT_23ec1506c;
          iVar8 = DAT_23ec1506c;
          DAT_23ec1506c = DAT_23ec1506c + 1;
        }
        if (DAT_23ec15070 != iVar8) {
          DAT_23ec15070 = iVar8;
          DAT_23eeb4ce0 = FUN_23e8cbd60(lVar12,DAT_23eeb3980,*(undefined8 *)(DAT_23eeb3980 + 0x18));
        }
        if (-1 < DAT_23eeb4ce0) {
          lVar3 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
          if (*(longlong *)(lVar3 + 8 + DAT_23eeb4ce0 * 0x10) != 0) goto LAB_23e316c24;
          DAT_23eeb4ce0 = FUN_23e8cbd60(lVar12,DAT_23eeb3980,*(undefined8 *)(DAT_23eeb3980 + 0x18));
          if (-1 < DAT_23eeb4ce0) {
            lVar12 = *(longlong *)(lVar3 + 8 + DAT_23eeb4ce0 * 0x10);
            goto LAB_23e317278;
          }
        }
LAB_23e316e29:
        plVar9 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeb3980);
        if ((plVar9 == (longlong *)0x0) || (*plVar9 == 0)) {
          uVar14 = 0x17;
          FUN_23e915740(param_1,&pcStack_68,DAT_23eeb3980);
          plVar9 = aplStack_58[0];
          plVar10 = DAT_23ed6a4f8;
          goto joined_r0x00023e31709c;
        }
      }
LAB_23e316c24:
      *(undefined4 *)(plVar4 + 5) = 0x17;
      plVar9 = (longlong *)FUN_23e91a870(param_1);
      if (plVar9 != (longlong *)0x0) {
        cVar7 = FUN_23e8d9ac0(pcVar1,DAT_23eeb3988,plVar9);
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (cVar7 != '\0') {
          cVar7 = FUN_23e8d9ac0(pcVar1,DAT_23eeb3990,pcVar6);
          if (cVar7 == '\0') {
            pcStack_68 = *(code **)(param_1 + 0x60);
            uStack_60 = *(undefined8 *)(param_1 + 0x68);
            plVar9 = *(longlong **)(param_1 + 0x70);
            uVar14 = 0x18;
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar10 = DAT_23ed6a4f8;
          }
          else {
            cVar7 = FUN_23e8d9ac0(pcVar1,DAT_23eeb3998,plVar2);
            if (cVar7 == '\0') {
              pcStack_68 = *(code **)(param_1 + 0x60);
              uStack_60 = *(undefined8 *)(param_1 + 0x68);
              plVar9 = *(longlong **)(param_1 + 0x70);
              uVar14 = 0x19;
              *(undefined8 *)(param_1 + 0x70) = 0;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              plVar10 = DAT_23ed6a4f8;
            }
            else {
              *(undefined4 *)(plVar4 + 5) = 0x1b;
              plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeb39a0);
              if (plVar9 == (longlong *)0x0) {
                pcStack_68 = *(code **)(param_1 + 0x60);
                uStack_60 = *(undefined8 *)(param_1 + 0x68);
                plVar9 = *(longlong **)(param_1 + 0x70);
                uVar14 = 0x1b;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar10 = DAT_23ed6a4f8;
              }
              else {
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                *(undefined4 *)(plVar4 + 5) = 0x1c;
                plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeb39a8);
                if (plVar9 == (longlong *)0x0) {
                  pcStack_68 = *(code **)(param_1 + 0x60);
                  uStack_60 = *(undefined8 *)(param_1 + 0x68);
                  plVar9 = *(longlong **)(param_1 + 0x70);
                  uVar14 = 0x1c;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  plVar10 = DAT_23ed6a4f8;
                }
                else {
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *(undefined4 *)(plVar4 + 5) = 0x1f;
                  plVar11 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeb39b0);
                  if (plVar11 == (longlong *)0x0) {
                    pcStack_68 = *(code **)(param_1 + 0x60);
                    uStack_60 = *(undefined8 *)(param_1 + 0x68);
                    plVar9 = *(longlong **)(param_1 + 0x70);
                    uVar14 = 0x1f;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    plVar10 = DAT_23ed6a4f8;
                  }
                  else {
                    iVar8 = FUN_23a35f020(plVar11);
                    lVar12 = *plVar11 + -1;
                    if (iVar8 != -1) {
                      *plVar11 = lVar12;
                      if (lVar12 == 0) {
                        (**(code **)(plVar11[1] + 0x30))();
                      }
                      if (iVar8 != 0) {
                        *(undefined4 *)(plVar4 + 5) = 0x20;
                        plVar9 = (longlong *)FUN_23e91bfe0(param_1,pcVar1,DAT_23eeb39b8);
                        if (plVar9 == (longlong *)0x0) {
                          pcStack_68 = *(code **)(param_1 + 0x60);
                          uStack_60 = *(undefined8 *)(param_1 + 0x68);
                          plVar9 = *(longlong **)(param_1 + 0x70);
                          uVar14 = 0x20;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          plVar10 = DAT_23ed6a4f8;
                          goto joined_r0x00023e31709c;
                        }
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                        }
                      }
                      lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar9 = *(longlong **)(lVar12 + 0x28);
                      plVar4 = (longlong *)plVar9[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar12 + 0x30);
                      *(undefined4 *)(plVar9 + 8) = 0xffffffff;
                      if (plVar4 != (longlong *)0x0) {
                        plVar9[2] = 0;
                        *plVar4 = *plVar4 + -1;
                        if (*plVar4 == 0) {
                          (**(code **)(plVar4[1] + 0x30))();
                        }
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      *(longlong *)pcVar6 = *(longlong *)pcVar6 + 1;
                      plVar9[0xf] = 0;
                      *(longlong *)pcVar1 = *(longlong *)pcVar1 + -1;
                      if (*(longlong *)pcVar1 == 0) {
                        (**(code **)(*(longlong *)(pcVar1 + 8) + 0x30))(pcVar1);
                      }
                      *plVar2 = *plVar2 + -1;
                      if (*plVar2 != 0) {
                        return pcVar6;
                      }
                      (**(code **)(plVar2[1] + 0x30))(plVar2);
                      return pcVar6;
                    }
                    pcStack_68 = *(code **)(param_1 + 0x60);
                    uStack_60 = *(undefined8 *)(param_1 + 0x68);
                    aplStack_58[0] = *(longlong **)(param_1 + 0x70);
                    uVar14 = 0x1f;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar11 = lVar12;
                    plVar9 = aplStack_58[0];
                    plVar10 = DAT_23ed6a4f8;
                    if (lVar12 == 0) {
                      (**(code **)(plVar11[1] + 0x30))();
                      plVar9 = aplStack_58[0];
                      plVar10 = DAT_23ed6a4f8;
                    }
                  }
                }
              }
            }
          }
          goto joined_r0x00023e31709c;
        }
      }
      plVar9 = *(longlong **)(param_1 + 0x70);
      pcStack_68 = *(code **)(param_1 + 0x60);
      uStack_60 = *(undefined8 *)(param_1 + 0x68);
      uVar14 = 0x17;
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar10 = DAT_23ed6a4f8;
      goto joined_r0x00023e31709c;
    }
  }
  pcStack_68 = *(code **)(param_1 + 0x60);
  uStack_60 = *(undefined8 *)(param_1 + 0x68);
  plVar9 = *(longlong **)(param_1 + 0x70);
  uVar14 = 0x16;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar10 = DAT_23ed6a4f8;
joined_r0x00023e31709c:
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
    pcVar6 = _PyRuntime_exref;
    plVar10[2] = 0;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar9 = plVar10;
    if ((aplStack_58[0] != (longlong *)0x0) &&
       (*aplStack_58[0] = *aplStack_58[0] + -1, *aplStack_58[0] == 0)) {
      (**(code **)(aplStack_58[0][1] + 0x30))(aplStack_58[0]);
    }
  }
  else if ((longlong *)plVar9[3] != plVar4) {
    if (plVar10 == (longlong *)0x0) {
      plVar10 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar10;
      *plVar10 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar10[3] = (longlong)plVar4;
    *plVar4 = *plVar4 + 1;
    lVar12 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)(plVar10 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar10 + 0x24) = uVar14;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar3 = plVar10[-1];
    puVar5 = *(undefined8 **)(lVar12 + 8);
    *puVar5 = plVar10 + -2;
    plVar10[-2] = lVar12;
    plVar10[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar5;
    *(longlong **)(lVar12 + 8) = plVar10 + -2;
    plVar10[2] = (longlong)plVar9;
    *plVar9 = *plVar9 + 1;
    plVar9 = plVar10;
    if ((aplStack_58[0] != (longlong *)0x0) &&
       (*aplStack_58[0] = *aplStack_58[0] + -1, *aplStack_58[0] == 0)) {
      (**(code **)(aplStack_58[0][1] + 0x30))();
    }
  }
  aplStack_58[0] = plVar9;
  FUN_23e8bba40(plVar4,&DAT_23ec5b754,pcVar1,plVar2,*(undefined8 *)(param_2 + 0xd8));
  if (DAT_23eeb4cf8 == plVar4) {
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))(plVar4);
    }
    DAT_23eeb4cf8 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar9 = *(longlong **)(lVar12 + 0x28);
  plVar4 = (longlong *)plVar9[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar9 + 8) = 0xffffffff;
  if (plVar4 != (longlong *)0x0) {
    plVar9[2] = 0;
    *plVar4 = *plVar4 + -1;
    if (*plVar4 == 0) {
      (**(code **)(plVar4[1] + 0x30))();
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
  FUN_23a33aa70(param_1,pcStack_68,uStack_60,aplStack_58[0]);
  return (code *)0x0;
}
