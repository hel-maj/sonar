/* ===== 23e2c3530 ui.home_tab:219 ===== */
/* ghidra_name=FUN_23e2c3530 entry=23e2c3530 size=4320 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_23e2c3530(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  code *pcVar6;
  int iVar7;
  longlong lVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong lVar14;
  undefined8 *puVar15;
  longlong *unaff_R15;
  longlong lStack_98;
  undefined8 uStack_90;
  undefined4 uStack_88;
  longlong lStack_78;
  undefined8 uStack_70;
  longlong *plStack_68;
  
  plVar10 = _DAT_23eeb0330;
  plVar1 = (longlong *)*param_3;
  plVar2 = (longlong *)param_3[1];
  if (_DAT_23eeb0330 == (longlong *)0x0) {
LAB_23e2c3579:
    _DAT_23eeb0330 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb0328,DAT_23eeb0380,0x28);
  }
  else {
    lVar8 = *_DAT_23eeb0330;
    if (1 < lVar8) {
      *_DAT_23eeb0330 = lVar8 + -1;
      goto LAB_23e2c3579;
    }
    if (_DAT_23eeb0330[2] != 0) {
      *_DAT_23eeb0330 = lVar8 + -1;
      if (lVar8 + -1 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      goto LAB_23e2c3579;
    }
  }
  plVar3 = _DAT_23eeb0330;
  lVar8 = *(longlong *)(param_1 + 0x38);
  plVar10 = _DAT_23eeb0330 + 9;
  lVar14 = *(longlong *)(lVar8 + 8);
  _DAT_23eeb0330[0xf] = lVar14;
  *(longlong **)(lVar8 + 8) = plVar10;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar10 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar10;
    if (plVar10 != (longlong *)0x0) {
      *plVar10 = *plVar10 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  *(undefined4 *)(plVar3 + 8) = 0;
  lVar8 = FUN_23e8f7770();
  if (lVar8 == 0) {
    unaff_R15 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    FUN_23e915740(param_1,&lStack_78,DAT_23eead9a0);
    uStack_88 = 0xdd;
    lStack_98 = lStack_78;
    uStack_90 = uStack_70;
    plVar9 = (longlong *)0x0;
    plVar10 = plStack_68;
    goto LAB_23e2c3db0;
  }
  *(undefined4 *)(plVar3 + 5) = 0xdd;
  plVar9 = (longlong *)FUN_23e91a870(param_1,lVar8);
  lVar8 = _DAT_23eeadc68;
  if (plVar9 == (longlong *)0x0) {
    lStack_98 = *(longlong *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    unaff_R15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    plVar11 = (longlong *)0x0;
    uStack_88 = 0xdd;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c3db0;
  }
  *(undefined4 *)(plVar3 + 5) = 0xde;
  plVar10 = (longlong *)FUN_23e915840(param_1,plVar9,_DAT_23eeadc60,*(undefined8 *)(lVar8 + 0x18));
  if (plVar10 == (longlong *)0x0) {
    lStack_98 = *(longlong *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    unaff_R15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0xde;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = (longlong *)0x0;
    goto LAB_23e2c3db0;
  }
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plVar11 = (longlong *)FUN_23e8bc2f0(plVar9,_DAT_23eead9b8);
  plVar10 = _DAT_23eeadc70;
  if (plVar11 == (longlong *)0x0) {
    lStack_98 = *(longlong *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    unaff_R15 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_88 = 0xdf;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e2c3db0;
  }
  lVar8 = *(longlong *)(param_1 + 0x10);
  plVar12 = *(longlong **)(lVar8 + 0xe28);
  if (plVar12 == (longlong *)0x0) {
    plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
  }
  else {
    lVar14 = plVar12[3];
    *(int *)(lVar8 + 0xec0) = *(int *)(lVar8 + 0xec0) + -1;
    *(longlong *)(lVar8 + 0xe28) = lVar14;
    *plVar12 = 1;
  }
  pcVar6 = _PyRuntime_exref;
  *(undefined1 (*) [16])(plVar12 + 4) = (undefined1  [16])0x0;
  lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
  lVar14 = plVar12[-1];
  puVar15 = *(undefined8 **)(lVar8 + 8);
  *puVar15 = plVar12 + -2;
  plVar12[-2] = lVar8;
  plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar15;
  *(longlong **)(lVar8 + 8) = plVar12 + -2;
  lVar14 = DAT_23eeae258;
  *plVar10 = *plVar10 + 1;
  plVar12[3] = (longlong)plVar10;
  lVar8 = *(longlong *)(lVar14 + 0x20);
  if (*(char *)(lVar8 + 10) == '\0') {
    plVar10 = (longlong *)FUN_23a37a020(lVar14,DAT_23eeadc78);
    if (plVar10 == (longlong *)0x0) goto LAB_23e2c3d03;
    lVar14 = *plVar10;
LAB_23e2c4292:
    if (lVar14 == 0) goto LAB_23e2c3d03;
LAB_23e2c3778:
    uVar4 = DAT_23ed6cd28;
    if (DAT_23ed6a4c0 == (longlong *)0x0) {
      plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + 1;
        DAT_23ed6a4c0 = plVar10;
        goto LAB_23e2c379b;
      }
LAB_23e2c4680:
      PyErr_PrintEx(0);
      Py_Exit(1);
LAB_23e2c4693:
      lStack_98 = *(longlong *)(param_1 + 0x60);
      plVar10 = *(longlong **)(param_1 + 0x70);
      uStack_88 = 0xf3;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uStack_90 = *(undefined8 *)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      goto LAB_23e2c3db0;
    }
LAB_23e2c379b:
    uStack_70 = uVar4;
    lStack_78 = lVar14;
    lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&lStack_78);
    if (lVar8 != 0) {
      plVar12[4] = lVar8;
      plVar10 = _DAT_23eeadc80;
      *_DAT_23eeadc80 = *_DAT_23eeadc80 + 1;
      plVar12[5] = (longlong)plVar10;
      plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if (plVar10 == (longlong *)0x0) {
        lStack_98 = *(longlong *)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
      }
      else {
        *(undefined4 *)(plVar3 + 5) = 0xdf;
        plVar12 = (longlong *)FUN_23e914090(param_1,plVar11,plVar10);
        *plVar11 = *plVar11 + -1;
        if (*plVar11 == 0) {
          (**(code **)(plVar11[1] + 0x30))(plVar11);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 == 0) {
          (**(code **)(plVar10[1] + 0x30))(plVar10);
        }
        if (plVar12 != (longlong *)0x0) {
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
          lVar8 = FUN_23e8f7640();
          if (lVar8 == 0) {
            unaff_R15 = (longlong *)0x0;
            FUN_23e915740(param_1,&lStack_78,DAT_23eead958);
            uStack_88 = 0xe7;
            lStack_98 = lStack_78;
            uStack_90 = uStack_70;
            plVar11 = (longlong *)0x0;
            plVar10 = plStack_68;
            goto LAB_23e2c3db0;
          }
          *(undefined4 *)(plVar3 + 5) = 0xe7;
          plVar11 = (longlong *)FUN_23e914090(param_1,lVar8,plVar9);
          lVar8 = _DAT_23eeadc88;
          if (plVar11 == (longlong *)0x0) {
            lStack_98 = *(longlong *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            unaff_R15 = (longlong *)0x0;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_88 = 0xe7;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c3db0;
          }
          *(undefined4 *)(plVar3 + 5) = 0xe8;
          plVar10 = (longlong *)FUN_23e95a860(param_1,plVar11,_DAT_23eead960,lVar8 + 0x18);
          if (plVar10 == (longlong *)0x0) {
            lStack_98 = *(longlong *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uStack_88 = 0xe8;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            unaff_R15 = (longlong *)0x0;
            goto LAB_23e2c3db0;
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar8 = _DAT_23eeada88;
          *(undefined4 *)(plVar3 + 5) = 0xe9;
          plVar10 = (longlong *)
                    FUN_23e915840(param_1,plVar11,_DAT_23eead970,*(undefined8 *)(lVar8 + 0x18));
          if (plVar10 == (longlong *)0x0) {
            lStack_98 = *(longlong *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uStack_88 = 0xe9;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            unaff_R15 = (longlong *)0x0;
            goto LAB_23e2c3db0;
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          lVar8 = FUN_23e8f6e60();
          if (lVar8 == 0) {
            FUN_23e915740(param_1,&lStack_78,DAT_23eead9e8);
            uStack_88 = 0xec;
            lStack_98 = lStack_78;
            uStack_90 = uStack_70;
            unaff_R15 = (longlong *)0x0;
            plVar10 = plStack_68;
            goto LAB_23e2c3db0;
          }
          *(undefined4 *)(plVar3 + 5) = 0xec;
          unaff_R15 = (longlong *)FUN_23e914090(param_1,lVar8,plVar2);
          if (unaff_R15 == (longlong *)0x0) {
            lStack_98 = *(longlong *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            uStack_88 = 0xec;
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c3db0;
          }
          plVar12 = (longlong *)FUN_23e8bc2f0(unaff_R15,_DAT_23eead9b8);
          plVar10 = _DAT_23eeadc90;
          if (plVar12 == (longlong *)0x0) {
LAB_23e2c44a8:
            lStack_98 = *(longlong *)(param_1 + 0x60);
            plVar10 = *(longlong **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            uStack_90 = *(undefined8 *)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c44ce:
            uStack_88 = 0xed;
          }
          else {
            lVar8 = *(longlong *)(param_1 + 0x10);
            plVar13 = *(longlong **)(lVar8 + 0xe28);
            if (plVar13 == (longlong *)0x0) {
              plVar13 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
            }
            else {
              lVar14 = plVar13[3];
              *(int *)(lVar8 + 0xec0) = *(int *)(lVar8 + 0xec0) + -1;
              *(longlong *)(lVar8 + 0xe28) = lVar14;
              *plVar13 = 1;
            }
            pcVar6 = _PyRuntime_exref;
            *(undefined1 (*) [16])(plVar13 + 4) = (undefined1  [16])0x0;
            lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
            lVar14 = plVar13[-1];
            puVar15 = *(undefined8 **)(lVar8 + 8);
            *puVar15 = plVar13 + -2;
            plVar13[-2] = lVar8;
            plVar13[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar15;
            *(longlong **)(lVar8 + 8) = plVar13 + -2;
            *plVar10 = *plVar10 + 1;
            plVar13[3] = (longlong)plVar10;
            lVar8 = FUN_23e8f7250();
            uVar4 = DAT_23ed6cd28;
            if (lVar8 == 0) {
              FUN_23e915740(param_1,&lStack_78,DAT_23eeadad0);
              lStack_98 = lStack_78;
              uStack_90 = uStack_70;
              plVar10 = plStack_68;
            }
            else {
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar10 == (longlong *)0x0) goto LAB_23e2c4680;
                *plVar10 = *plVar10 + 1;
                DAT_23ed6a4c0 = plVar10;
              }
              uStack_70 = uVar4;
              lStack_78 = lVar8;
              lVar8 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&lStack_78);
              if (lVar8 != 0) {
                plVar13[4] = lVar8;
                plVar10 = _DAT_23eeadc98;
                *_DAT_23eeadc98 = *_DAT_23eeadc98 + 1;
                plVar13[5] = (longlong)plVar10;
                plVar10 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar13);
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                if (plVar10 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0xed;
                  plVar13 = (longlong *)FUN_23e914090(param_1,plVar12,plVar10);
                  lVar8 = *plVar12;
                  *plVar12 = lVar8 + -1;
                  if (lVar8 + -1 == 0) {
                    (**(code **)(plVar12[1] + 0x30))();
                  }
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  if (plVar13 != (longlong *)0x0) {
                    *plVar13 = *plVar13 + -1;
                    if (*plVar13 == 0) {
                      (**(code **)(plVar13[1] + 0x30))(plVar13);
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xf3;
                    plVar10 = (longlong *)FUN_23e915840(param_1,plVar11,_DAT_23eeada70,unaff_R15);
                    if (plVar10 != (longlong *)0x0) {
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        (**(code **)(plVar10[1] + 0x30))(plVar10);
                      }
                      lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
                      plVar10 = *(longlong **)(lVar8 + 0x28);
                      plVar3 = (longlong *)plVar10[2];
                      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) =
                           *(undefined8 *)(lVar8 + 0x30);
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
                      lVar8 = *(longlong *)(param_1 + 0x10);
                      plVar10[0xf] = 0;
                      puVar15 = *(undefined8 **)(lVar8 + 0xe20);
                      if (puVar15 == (undefined8 *)0x0) {
                        puVar15 = (undefined8 *)FUN_23e916a20(PyTuple_Type_exref,2);
                      }
                      else {
                        uVar4 = puVar15[3];
                        *(int *)(lVar8 + 0xebc) = *(int *)(lVar8 + 0xebc) + -1;
                        *(undefined8 *)(lVar8 + 0xe20) = uVar4;
                        *puVar15 = 1;
                      }
                      lVar8 = *(longlong *)
                               (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) +
                               0x2e8);
                      uVar4 = puVar15[-1];
                      puVar5 = *(undefined8 **)(lVar8 + 8);
                      *puVar5 = puVar15 + -2;
                      puVar15[-2] = lVar8;
                      puVar15[-1] = (ulonglong)((uint)uVar4 & 3) | (ulonglong)puVar5;
                      *(undefined8 **)(lVar8 + 8) = puVar15 + -2;
                      *plVar9 = *plVar9 + 1;
                      puVar15[3] = plVar9;
                      *plVar11 = *plVar11 + 1;
                      puVar15[4] = plVar11;
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        (**(code **)(plVar9[1] + 0x30))(plVar9);
                      }
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        (**(code **)(plVar11[1] + 0x30))(plVar11);
                      }
                      *unaff_R15 = *unaff_R15 + -1;
                      if (*unaff_R15 == 0) {
                        (**(code **)(unaff_R15[1] + 0x30))(unaff_R15);
                      }
                      *plVar1 = *plVar1 + -1;
                      if (*plVar1 == 0) {
                        (**(code **)(plVar1[1] + 0x30))(plVar1);
                      }
                      *plVar2 = *plVar2 + -1;
                      if (*plVar2 != 0) {
                        return puVar15;
                      }
                      (**(code **)(plVar2[1] + 0x30))(plVar2);
                      return puVar15;
                    }
                    goto LAB_23e2c4693;
                  }
                  goto LAB_23e2c44a8;
                }
                lStack_98 = *(longlong *)(param_1 + 0x60);
                plVar10 = *(longlong **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uStack_90 = *(undefined8 *)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                lVar8 = *plVar12;
                *plVar12 = lVar8 + -1;
                if (lVar8 + -1 == 0) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
                goto LAB_23e2c44ce;
              }
              lStack_98 = *(longlong *)(param_1 + 0x60);
              plVar10 = *(longlong **)(param_1 + 0x70);
              *(undefined8 *)(param_1 + 0x70) = 0;
              uStack_90 = *(undefined8 *)(param_1 + 0x68);
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            }
            lVar8 = *plVar12;
            *plVar12 = lVar8 + -1;
            if (lVar8 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            *plVar13 = *plVar13 + -1;
            uStack_88 = 0xf0;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
              uStack_88 = 0xf0;
            }
          }
          goto LAB_23e2c3db0;
        }
        lStack_98 = *(longlong *)(param_1 + 0x60);
        plVar10 = *(longlong **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        uStack_90 = *(undefined8 *)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      }
      unaff_R15 = (longlong *)0x0;
      plVar11 = (longlong *)0x0;
      uStack_88 = 0xdf;
      goto LAB_23e2c3db0;
    }
    lStack_98 = *(longlong *)(param_1 + 0x60);
    plVar10 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    uStack_90 = *(undefined8 *)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  }
  else {
    iVar7 = *(int *)(lVar8 + 0xc);
    if (*(int *)(lVar8 + 0xc) == 0) {
      *(int *)(lVar8 + 0xc) = _DAT_23ec14e6c;
      iVar7 = _DAT_23ec14e6c;
      _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
    }
    if (_DAT_23ec14e64 != iVar7) {
      _DAT_23ec14e64 = iVar7;
      _DAT_23eeb0320 = FUN_23e8cbd60(lVar8,DAT_23eeadc78,*(undefined8 *)(DAT_23eeadc78 + 0x18));
    }
    if (-1 < _DAT_23eeb0320) {
      unaff_R15 = (longlong *)(lVar8 + 0x20 + (1L << (*(byte *)(lVar8 + 9) & 0x3f)));
      lVar14 = unaff_R15[_DAT_23eeb0320 * 2 + 1];
      if (lVar14 != 0) goto LAB_23e2c3778;
      _DAT_23eeb0320 = FUN_23e8cbd60(lVar8,DAT_23eeadc78,*(undefined8 *)(DAT_23eeadc78 + 0x18));
      if (-1 < _DAT_23eeb0320) {
        lVar14 = unaff_R15[_DAT_23eeb0320 * 2 + 1];
        goto LAB_23e2c4292;
      }
    }
LAB_23e2c3d03:
    plVar10 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeadc78);
    if ((plVar10 != (longlong *)0x0) && (lVar14 = *plVar10, lVar14 != 0)) goto LAB_23e2c3778;
    FUN_23e915740(param_1,&lStack_78,DAT_23eeadc78);
    lStack_98 = lStack_78;
    uStack_90 = uStack_70;
    plVar10 = plStack_68;
  }
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  *plVar12 = *plVar12 + -1;
  if (*plVar12 == 0) {
    unaff_R15 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
    (**(code **)(plVar12[1] + 0x30))(plVar12);
    uStack_88 = 0xe1;
  }
  else {
    uStack_88 = 0xe1;
    unaff_R15 = (longlong *)0x0;
    plVar11 = (longlong *)0x0;
  }
LAB_23e2c3db0:
  plVar12 = DAT_23ed6a4f8;
  if (plVar10 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar10 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar10;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar6 = _PyRuntime_exref;
    plVar12[2] = 0;
    plVar12[3] = (longlong)plVar3;
    *plVar3 = *plVar3 + 1;
    lVar8 = *(longlong *)(pcVar6 + 0x1f8);
    *(undefined4 *)((longlong)plVar12 + 0x24) = uStack_88;
    lVar8 = *(longlong *)(lVar8 + 0x10);
    *(undefined4 *)(plVar12 + 4) = 0xffffffff;
    lVar8 = *(longlong *)(lVar8 + 0x2e8);
    lVar14 = plVar12[-1];
    puVar15 = *(undefined8 **)(lVar8 + 8);
    *puVar15 = plVar12 + -2;
    plVar12[-2] = lVar8;
    plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar15;
    *(longlong **)(lVar8 + 8) = plVar12 + -2;
    plVar13 = plVar12;
  }
  else {
    plVar13 = plVar10;
    if ((longlong *)plVar10[3] != plVar3) {
      if (DAT_23ed6a4f8 == (longlong *)0x0) {
        plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        plVar13 = (longlong *)*DAT_23ed6a4f8;
        *DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = plVar13;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      plVar12[3] = (longlong)plVar3;
      *plVar3 = *plVar3 + 1;
      *(undefined4 *)((longlong)plVar12 + 0x24) = uStack_88;
      pcVar6 = _PyRuntime_exref;
      *(undefined4 *)(plVar12 + 4) = 0xffffffff;
      lVar8 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar6 + 0x1f8) + 0x10) + 0x2e8);
      lVar14 = plVar12[-1];
      puVar15 = *(undefined8 **)(lVar8 + 8);
      *puVar15 = plVar12 + -2;
      plVar12[-2] = lVar8;
      plVar12[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar15;
      lVar14 = *plVar10;
      *(longlong **)(lVar8 + 8) = plVar12 + -2;
      plVar12[2] = (longlong)plVar10;
      plVar13 = plVar12;
      if (lVar14 == 0) {
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
    }
  }
  FUN_23e8bba40(plVar3,"ooooo",plVar1,plVar2,plVar9,plVar11,unaff_R15);
  if (_DAT_23eeb0330 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eeb0330 = (longlong *)0x0;
  }
  lVar8 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar10 = *(longlong **)(lVar8 + 0x28);
  plVar3 = (longlong *)plVar10[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar8 + 0x30);
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
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((unaff_R15 != (longlong *)0x0) && (*unaff_R15 = *unaff_R15 + -1, *unaff_R15 == 0)) {
    (**(code **)(unaff_R15[1] + 0x30))(unaff_R15);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,lStack_98,uStack_90,plVar13);
  return (undefined8 *)0x0;
}
