/* ===== 23e887a60 workers.fishing.store_fish:71 ===== */
/* ghidra_name=FUN_23e887a60 entry=23e887a60 size=12112 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23e887a60(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  code *pcVar17;
  undefined8 uVar18;
  code *pcVar19;
  code *pcVar20;
  longlong lVar21;
  undefined4 uVar22;
  undefined1 auVar23 [8];
  longlong *plStack_140;
  code *pcStack_138;
  longlong *plStack_130;
  longlong *plStack_128;
  longlong *plStack_120;
  code *pcStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_100;
  code *pcStack_f8;
  code *pcStack_e8;
  longlong *plStack_c8;
  undefined8 uStack_c0;
  undefined1 auStack_b8 [8];
  code *pcStack_b0;
  code *pcStack_a8;
  undefined1 auStack_98 [16];
  code *pcStack_88;
  undefined8 uStack_80;
  longlong *plStack_78;
  
  plVar9 = _DAT_23eede6b8;
  plVar2 = (longlong *)*param_3;
  pcStack_a8 = (code *)0x0;
  auStack_b8 = (undefined1  [8])0x0;
  pcStack_b0 = (code *)0x0;
  if (_DAT_23eede6b8 == (longlong *)0x0) {
LAB_23e887ac5:
    _DAT_23eede6b8 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eede6b0,DAT_23eede708,0x78);
  }
  else {
    lVar10 = *_DAT_23eede6b8;
    if (1 < lVar10) {
      *_DAT_23eede6b8 = lVar10 + -1;
      goto LAB_23e887ac5;
    }
    if (_DAT_23eede6b8[2] != 0) {
      *_DAT_23eede6b8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e887ac5;
    }
  }
  plVar3 = _DAT_23eede6b8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar9 = _DAT_23eede6b8 + 9;
  lVar21 = *(longlong *)(lVar10 + 8);
  _DAT_23eede6b8[0xf] = lVar21;
  *(longlong **)(lVar10 + 8) = plVar9;
  if ((lVar21 != 0) &&
     (((*(char *)(lVar21 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar21 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar21 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar21 + 0x38))) && (plVar3[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar21 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar18 = DAT_23eedc808;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar9 = (longlong *)FUN_23e8bc2f0(plVar2,uVar18);
  if (plVar9 == (longlong *)0x0) {
LAB_23e888bc0:
    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcStack_b0 = *(code **)(param_1 + 0x68);
    pcStack_a8 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcStack_a8 != (code *)0x0) {
      plVar9 = *(longlong **)(pcStack_a8 + 0x18);
      goto joined_r0x00023e888bf7;
    }
  }
  else {
    iVar7 = FUN_23a35f020();
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      (**(code **)(plVar9[1] + 0x30))();
    }
    if (iVar7 == -1) {
LAB_23e8895c0:
      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_b0 = *(code **)(param_1 + 0x68);
      pcStack_a8 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcStack_a8 != (code *)0x0) {
        plVar9 = *(longlong **)(pcStack_a8 + 0x18);
        goto joined_r0x00023e888bf7;
      }
    }
    else {
      if (iVar7 == 0) {
LAB_23e887b88:
        pcVar17 = _Py_NoneStruct_exref;
        plVar12 = (longlong *)0x0;
        plVar11 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        pcStack_138 = (code *)0x0;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        plStack_128 = (longlong *)0x0;
        plStack_130 = (longlong *)0x0;
        plStack_120 = (longlong *)0x0;
        plStack_110 = (longlong *)0x0;
        pcStack_118 = (code *)0x0;
        plStack_108 = (longlong *)0x0;
        pcStack_f8 = (code *)0x0;
        plStack_100 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
LAB_23e887c13:
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar3 = *(longlong **)(lVar10 + 0x28);
        plVar13 = (longlong *)plVar3[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar3 + 8) = 0xffffffff;
        if (plVar13 != (longlong *)0x0) {
          plVar3[2] = 0;
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
        }
        *plVar3 = *plVar3 + -1;
        if (*plVar3 == 0) {
          (**(code **)(plVar3[1] + 0x30))(plVar3);
        }
        plVar3[0xf] = 0;
        if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
        if (plVar11 != (longlong *)0x0) {
LAB_23e887c75:
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
LAB_23e888b30:
            (**(code **)(plVar11[1] + 0x30))(plVar11);
          }
        }
        if (plVar12 != (longlong *)0x0) {
LAB_23e887c85:
          *plVar12 = *plVar12 + -1;
          if (*plVar12 == 0) {
            (**(code **)(plVar12[1] + 0x30))(plVar12);
          }
        }
        if ((plStack_140 != (longlong *)0x0) &&
           (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_140[1] + 0x30))(plStack_140);
        }
        if ((plStack_100 != (longlong *)0x0) &&
           (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_100[1] + 0x30))(plStack_100);
        }
        if ((pcStack_f8 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_f8, *(longlong *)pcStack_f8 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_f8 + 8) + 0x30))(pcStack_f8);
        }
        if ((plStack_108 != (longlong *)0x0) &&
           (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_108[1] + 0x30))(plStack_108);
        }
        if ((pcStack_118 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
        }
        if ((plStack_110 != (longlong *)0x0) &&
           (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_110[1] + 0x30))(plStack_110);
        }
        if ((plStack_120 != (longlong *)0x0) &&
           (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_120[1] + 0x30))(plStack_120);
        }
        if ((plStack_130 != (longlong *)0x0) &&
           (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_130[1] + 0x30))(plStack_130);
        }
        if ((plStack_128 != (longlong *)0x0) &&
           (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_128[1] + 0x30))(plStack_128);
        }
        if ((pcStack_138 != (code *)0x0) &&
           (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1,
           lVar10 + -1 == 0)) {
          (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))(pcStack_138);
        }
        *plVar2 = *plVar2 + -1;
        if (*plVar2 != 0) {
          return pcVar17;
        }
        (**(code **)(plVar2[1] + 0x30))(plVar2);
        return pcVar17;
      }
      lVar10 = FUN_23e8dbf70();
      if (lVar10 == 0) {
        FUN_23e915740(param_1,auStack_b8,DAT_23eedc820);
        if (pcStack_a8 != (code *)0x0) {
          plVar9 = *(longlong **)(pcStack_a8 + 0x18);
          goto joined_r0x00023e888bf7;
        }
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedc878);
        if (plVar9 == (longlong *)0x0) goto LAB_23e888bc0;
        plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
        if (plVar11 == (longlong *)0x0) {
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          pcStack_a8 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
            if (pcStack_a8 != (code *)0x0) {
              plVar9 = *(longlong **)(pcStack_a8 + 0x18);
joined_r0x00023e888bf7:
              if (plVar3 == plVar9) {
                pcStack_138 = (code *)0x0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_108 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcVar20 = pcStack_a8;
              }
              else {
                plVar9 = (longlong *)0x0;
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_108 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
                plStack_140 = (longlong *)0x0;
                iVar7 = 0x49;
                pcStack_e8 = _PyRuntime_exref;
LAB_23e888c9d:
                pcVar17 = pcStack_a8;
                pcVar20 = DAT_23ed6a4f8;
                if (DAT_23ed6a4f8 == (code *)0x0) {
                  pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                }
                else {
                  pcVar19 = *(code **)DAT_23ed6a4f8;
                  *(undefined8 *)DAT_23ed6a4f8 = 1;
                  DAT_23ed6a4f8 = pcVar19;
                  DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                }
                *(longlong **)(pcVar20 + 0x18) = plVar3;
                *plVar3 = *plVar3 + 1;
                lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                *(int *)(pcVar20 + 0x24) = iVar7;
                *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
                lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
                lVar21 = *(longlong *)(pcVar20 + -8);
                plVar13 = *(longlong **)(lVar10 + 8);
                *plVar13 = (longlong)(pcVar20 + -0x10);
                *(longlong *)(pcVar20 + -0x10) = lVar10;
                *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                *(code **)(lVar10 + 8) = pcVar20 + -0x10;
                *(code **)(pcVar20 + 0x10) = pcVar17;
                *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                if ((pcStack_a8 != (code *)0x0) &&
                   (*(longlong *)pcStack_a8 = *(longlong *)pcStack_a8 + -1,
                   *(longlong *)pcStack_a8 == 0)) {
                  (**(code **)(*(longlong *)(pcStack_a8 + 8) + 0x30))();
                }
              }
              goto LAB_23e888d48;
            }
          }
          else if (pcStack_a8 != (code *)0x0) {
            plVar9 = *(longlong **)(pcStack_a8 + 0x18);
            goto joined_r0x00023e888bf7;
          }
        }
        else {
          *(undefined4 *)(plVar3 + 5) = 0x49;
          plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))();
          }
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            (**(code **)(plVar11[1] + 0x30))();
          }
          if (plVar12 != (longlong *)0x0) {
            uVar8 = FUN_23a35f020();
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))();
            }
            if (uVar8 != 0xffffffff) {
              if ((uVar8 & 1) == 0) goto LAB_23e887b88;
              lVar10 = FUN_23e8dbf70();
              if (lVar10 == 0) {
                FUN_23e915740(param_1,auStack_b8,DAT_23eedc820);
                pcVar17 = pcStack_a8;
                auVar23 = auStack_b8;
                pcVar20 = pcStack_b0;
              }
              else {
                plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,DAT_23eedc888);
                if (plVar9 != (longlong *)0x0) {
                  plVar11 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
                  if (plVar11 == (longlong *)0x0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar9 = *plVar9 + -1;
                    pcVar17 = pcStack_a8;
                    auVar23 = auStack_b8;
                    pcVar20 = pcStack_b0;
                    if (*plVar9 == 0) {
                      (**(code **)(plVar9[1] + 0x30))(plVar9);
                      pcVar17 = pcStack_a8;
                      auVar23 = auStack_b8;
                      pcVar20 = pcStack_b0;
                    }
                    goto LAB_23e8890c1;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0x4d;
                  plVar12 = (longlong *)FUN_23e914090(param_1,plVar9,plVar11);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (plVar12 != (longlong *)0x0) {
                    plVar13 = (longlong *)FUN_23a388310(plVar12);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      (**(code **)(plVar12[1] + 0x30))(plVar12);
                    }
                    if (plVar13 != (longlong *)0x0) {
                      pcVar20 = (code *)auStack_b8;
                      plVar9 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if ((plVar9 == (longlong *)0x0) &&
                         (plVar9 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,0,4),
                         plVar9 == (longlong *)0x0)) {
                        plStack_140 = (longlong *)0x0;
                        plVar12 = (longlong *)0x0;
                        plVar11 = (longlong *)0x0;
                        goto LAB_23e889caf;
                      }
                      plVar11 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if (plVar11 == (longlong *)0x0) {
                        plVar12 = (longlong *)0x0;
                        plVar11 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,1,4);
                        plStack_140 = (longlong *)0x0;
                        if (plVar11 == (longlong *)0x0) goto LAB_23e889caf;
                      }
                      plVar12 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                      if (plVar12 == (longlong *)0x0) goto LAB_23e88a143;
                      goto LAB_23e88802e;
                    }
                  }
                }
                pcVar17 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar20 = *(code **)(param_1 + 0x68);
              }
LAB_23e8890c1:
              do {
                plVar12 = (longlong *)0x0;
                plVar11 = (longlong *)0x0;
                plVar9 = (longlong *)0x0;
                pcStack_138 = (code *)0x0;
                uVar22 = 0x4d;
                plStack_128 = (longlong *)0x0;
                plStack_130 = (longlong *)0x0;
                plStack_120 = (longlong *)0x0;
                plStack_110 = (longlong *)0x0;
                pcStack_118 = (code *)0x0;
                plStack_108 = (longlong *)0x0;
                pcStack_f8 = (code *)0x0;
                plStack_100 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_a8 = pcVar17;
                auStack_b8 = auVar23;
                pcStack_b0 = pcVar20;
LAB_23e889155:
                pcVar17 = pcStack_a8;
                auStack_98._8_8_ = pcStack_b0;
                auStack_98._0_8_ = auStack_b8;
                pcStack_a8 = (code *)0x0;
                auStack_b8 = (undefined1  [8])0x0;
                pcStack_b0 = (code *)0x0;
                pcStack_88 = pcVar17;
                plVar14 = *(longlong **)(param_1 + 0x138);
                if (plVar14 != (longlong *)0x0) {
                  *plVar14 = *plVar14 + 1;
                }
                pcVar19 = DAT_23ed6a4f8;
                if (pcVar17 == (code *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar17 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar17;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e8 = _PyRuntime_exref;
                  *(longlong *)(pcVar19 + 0x10) = 0;
                  *(longlong **)(pcVar19 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                  *(undefined4 *)(pcVar19 + 0x24) = uVar22;
                  lVar10 = *(longlong *)(lVar10 + 0x10);
                  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
                  lVar10 = *(longlong *)(lVar10 + 0x2e8);
                  lVar21 = *(longlong *)(pcVar19 + -8);
                  plVar13 = *(longlong **)(lVar10 + 8);
                  *plVar13 = (longlong)(pcVar19 + -0x10);
                  *(longlong *)(pcVar19 + -0x10) = lVar10;
                  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                  *(code **)(lVar10 + 8) = pcVar19 + -0x10;
                  if ((pcStack_88 != (code *)0x0) &&
                     (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                     *(longlong *)pcStack_88 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))(pcStack_88);
                  }
                }
                else {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar20 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar20;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e8 = _PyRuntime_exref;
                  *(longlong **)(pcVar19 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
                  *(undefined4 *)(pcVar19 + 0x24) = uVar22;
                  lVar10 = *(longlong *)(lVar10 + 0x10);
                  *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
                  lVar10 = *(longlong *)(lVar10 + 0x2e8);
                  lVar21 = *(longlong *)(pcVar19 + -8);
                  plVar13 = *(longlong **)(lVar10 + 8);
                  *plVar13 = (longlong)(pcVar19 + -0x10);
                  *(longlong *)(pcVar19 + -0x10) = lVar10;
                  *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
                  *(code **)(lVar10 + 8) = pcVar19 + -0x10;
                  *(code **)(pcVar19 + 0x10) = pcVar17;
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                  if ((pcStack_88 != (code *)0x0) &&
                     (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                     *(longlong *)pcStack_88 == 0)) {
                    (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
                  }
                }
                pcVar20 = _Py_NoneStruct_exref;
                pcStack_88 = pcVar19;
                if (((code *)auStack_98._0_8_ != (code *)0x0) &&
                   ((code *)auStack_98._0_8_ != _Py_NoneStruct_exref)) {
                  FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,&pcStack_88);
                }
                plVar13 = *(longlong **)(auStack_98._8_8_ + 0x28);
                if (pcStack_88 == pcVar20) {
                  pcVar17 = (code *)0x0;
                }
                else {
                  pcVar17 = pcStack_88;
                  if (pcStack_88 != (code *)0x0) {
                    *(longlong *)pcStack_88 = *(longlong *)pcStack_88 + 1;
                  }
                }
                *(code **)(auStack_98._8_8_ + 0x28) = pcVar17;
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                plVar13 = *(longlong **)(param_1 + 0x138);
                *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
                  (**(code **)(plVar13[1] + 0x30))();
                }
                *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
                if (*(longlong *)auStack_98._0_8_ == 0) {
                  (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                }
                if ((pcStack_88 != (code *)0x0) &&
                   (*(longlong *)pcStack_88 = *(longlong *)pcStack_88 + -1,
                   *(longlong *)pcStack_88 == 0)) {
                  (**(code **)(*(longlong *)(pcStack_88 + 8) + 0x30))();
                }
                pcStack_88 = (code *)0x0;
                auStack_98 = (undefined1  [16])0x0;
                iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                      *(undefined8 *)PyExc_Exception_exref);
                if (iVar7 == 0) {
                  pcVar17 = *(code **)(param_1 + 0x138);
                  pcStack_b0 = pcVar17;
                  if ((pcVar17 == pcVar20) || (pcVar17 == (code *)0x0)) {
                    pcVar20 = (code *)0x0;
                    auVar23 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
                    pcVar17 = (code *)PyUnicode_FromString("No active exception to reraise");
                    pcVar19 = *(code **)(param_1 + 0x138);
                    iVar7 = 0x4c;
                    *(longlong *)auVar23 = *(longlong *)auVar23 + 1;
                    goto LAB_23e889ab0;
                  }
                  auVar23 = *(undefined1 (*) [8])(pcVar17 + 8);
                  pcVar20 = *(code **)(pcVar17 + 0x28);
                  *(longlong *)pcVar17 = *(longlong *)pcVar17 + 1;
                  *(longlong *)auVar23 = *(longlong *)auVar23 + 1;
                  iVar7 = 0;
                  pcVar19 = pcVar17;
                  if (pcVar20 == (code *)0x0) {
                    *(longlong **)(param_1 + 0x138) = plVar14;
                  }
                  else {
                    *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                    if (*(longlong **)(pcVar20 + 0x18) == plVar3) {
                      *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                    }
                    *(longlong **)(param_1 + 0x138) = plVar14;
                  }
LAB_23e889920:
                  pcStack_a8 = (code *)0x0;
                  _auStack_b8 = (undefined1  [16])0x0;
                  *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
                  if (*(longlong *)pcVar19 == 0) {
                    (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
                  }
                  auStack_b8 = auVar23;
                  pcStack_b0 = pcVar17;
                  if (pcVar20 == (code *)0x0) {
                    pcStack_a8 = (code *)0x0;
                    if (iVar7 == 0) {
                      iVar7 = (int)plVar3[5];
                    }
                    goto LAB_23e88972b;
                  }
LAB_23e88997f:
                  if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23e888d48;
                  pcStack_a8 = pcVar20;
                  if (iVar7 == 0) {
                    iVar7 = (int)plVar3[5];
                  }
                  goto LAB_23e888c9d;
                }
                plVar13 = *(longlong **)(param_1 + 0x138);
                *plVar13 = *plVar13 + 1;
                uVar18 = FUN_23a3a0d40(DAT_23ed6cf28);
                plVar16 = _DAT_23eedc978;
                lVar10 = *(longlong *)(param_1 + 0x10);
                plVar15 = *(longlong **)(lVar10 + 0xe20);
                if (plVar15 == (longlong *)0x0) {
                  plVar15 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar21 = plVar15[3];
                  *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
                  *(longlong *)(lVar10 + 0xe20) = lVar21;
                  *plVar15 = 1;
                }
                plVar15[4] = 0;
                lVar10 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_e8 + 0x1f8) + 0x10) + 0x2e8);
                lVar21 = plVar15[-1];
                puVar4 = *(undefined8 **)(lVar10 + 8);
                *puVar4 = plVar15 + -2;
                plVar15[-2] = lVar10;
                plVar15[-1] = (ulonglong)((uint)lVar21 & 3) | (ulonglong)puVar4;
                *(longlong **)(lVar10 + 8) = plVar15 + -2;
                *plVar16 = *plVar16 + 1;
                plVar15[3] = (longlong)plVar16;
                uVar5 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 != (longlong *)0x0) {
LAB_23e889452:
                  uStack_c0 = uVar5;
                  plStack_c8 = plVar13;
                  lVar10 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_c8);
                  if (lVar10 == 0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar15 = *plVar15 + -1;
                    pcVar17 = pcStack_b0;
                    auVar23 = auStack_b8;
                    pcVar20 = pcStack_a8;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                      pcVar17 = pcStack_b0;
                      auVar23 = auStack_b8;
                      pcVar20 = pcStack_a8;
                    }
                  }
                  else {
                    plVar15[4] = lVar10;
                    plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar15);
                    *plVar15 = *plVar15 + -1;
                    if (*plVar15 == 0) {
                      (**(code **)(plVar15[1] + 0x30))(plVar15);
                    }
                    if (plVar16 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0x6a;
                      plVar15 = (longlong *)FUN_23e914090(param_1,uVar18);
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        (**(code **)(plVar16[1] + 0x30))(plVar16);
                      }
                      if (plVar15 != (longlong *)0x0) {
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          (**(code **)(plVar15[1] + 0x30))(plVar15);
                        }
                        *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        plVar3 = *(longlong **)(param_1 + 0x138);
                        *(longlong **)(param_1 + 0x138) = plVar14;
                        pcVar17 = pcVar20;
                        if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
                          (**(code **)(plVar3[1] + 0x30))();
                        }
                        goto LAB_23e887c13;
                      }
                    }
                    auVar23 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcVar17 = *(code **)(param_1 + 0x68);
                  }
                  pcStack_a8 = (code *)0x0;
                  _auStack_b8 = (undefined1  [16])0x0;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  pcVar19 = *(code **)(param_1 + 0x138);
                  iVar7 = 0x6a;
LAB_23e889ab0:
                  *(longlong **)(param_1 + 0x138) = plVar14;
                  if (pcVar19 != (code *)0x0) goto LAB_23e889920;
                  auStack_b8 = auVar23;
                  pcStack_b0 = pcVar17;
                  if (pcVar20 != (code *)0x0) goto LAB_23e88997f;
                  pcStack_a8 = (code *)0x0;
                  goto LAB_23e88972b;
                }
                plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar16 != (longlong *)0x0) {
                  *plVar16 = *plVar16 + 1;
                  DAT_23ed6a4c0 = plVar16;
                  goto LAB_23e889452;
                }
                PyErr_PrintEx(0);
                Py_Exit(1);
LAB_23e88a143:
                plVar12 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,2,4);
                plStack_140 = (longlong *)0x0;
                if (plVar12 != (longlong *)0x0) {
LAB_23e88802e:
                  plStack_140 = (longlong *)(**(code **)(plVar13[1] + 0xe0))(plVar13);
                  if (((plStack_140 == (longlong *)0x0) &&
                      (plStack_140 = (longlong *)FUN_23a3c1b70(param_1,pcVar20,3,4),
                      plStack_140 == (longlong *)0x0)) ||
                     (cVar6 = FUN_23a3884a0(param_1,pcVar20,plVar13,4), cVar6 == '\0'))
                  goto LAB_23e889caf;
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (*plVar11 == 0) {
                    (**(code **)(plVar11[1] + 0x30))(plVar11);
                  }
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (*plStack_140 == 0) {
                    (**(code **)(plStack_140[1] + 0x30))();
                  }
                  plStack_100 = (longlong *)FUN_23e8c6640(plVar12,plVar9);
                  if (plStack_100 == (longlong *)0x0) {
                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_b0 = *(code **)(param_1 + 0x68);
                    pcStack_a8 = *(code **)(param_1 + 0x70);
                    pcStack_138 = (code *)0x0;
                    uVar22 = 0x4e;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    plStack_128 = (longlong *)0x0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    pcStack_118 = (code *)0x0;
                    plStack_108 = (longlong *)0x0;
                    pcStack_f8 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    goto LAB_23e889155;
                  }
                  pcStack_f8 = (code *)FUN_23e8c6640(plStack_140,plVar11);
                  if (pcStack_f8 != (code *)0x0) {
                    lVar10 = FUN_23e8dbf70();
                    if (lVar10 == 0) {
                      FUN_23e915740(param_1,pcVar20,DAT_23eedc820);
                    }
                    else {
                      plVar13 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eedc898);
                      if (plVar13 == (longlong *)0x0) {
LAB_23e88a2be:
                        pcStack_a8 = *(code **)(param_1 + 0x70);
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      }
                      else {
                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar2,DAT_23eedc808);
                        if (plVar14 != (longlong *)0x0) {
                          *(undefined4 *)(plVar3 + 5) = 0x51;
                          plStack_108 = (longlong *)FUN_23e914090(param_1,plVar13,plVar14);
                          *plVar13 = *plVar13 + -1;
                          if (*plVar13 == 0) {
                            FUN_23a334bc0();
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            FUN_23a334bc0();
                          }
                          if (plStack_108 == (longlong *)0x0) goto LAB_23e88a2be;
                          lVar10 = FUN_23e8dbe20();
                          if (lVar10 == 0) {
                            FUN_23e915740(param_1,pcVar20,_DAT_23eedc8a0);
                            pcStack_118 = (code *)0x0;
                          }
                          else {
                            *(undefined4 *)(plVar3 + 5) = 0x52;
                            pcStack_118 = (code *)FUN_23e915840(param_1,lVar10,_DAT_23eedc8a8,
                                                                plStack_108);
                            if (pcStack_118 != (code *)0x0) {
                              *(undefined4 *)(plVar3 + 5) = 0x53;
                              plStack_110 = (longlong *)
                                            FUN_23e91bfe0(param_1,pcStack_118,_DAT_23eedc8b0);
                              if (plStack_110 == (longlong *)0x0) {
                                auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcStack_b0 = *(code **)(param_1 + 0x68);
                                pcStack_a8 = *(code **)(param_1 + 0x70);
                                uVar22 = 0x53;
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                pcStack_138 = (code *)0x0;
                                plStack_128 = (longlong *)0x0;
                                plStack_130 = (longlong *)0x0;
                                plStack_120 = (longlong *)0x0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                lVar10 = FUN_23e8dbe20();
                                if (lVar10 == 0) {
                                  FUN_23e915740(param_1,pcVar20,_DAT_23eedc8a0);
                                  uVar22 = 0x55;
                                  pcStack_138 = (code *)0x0;
                                  plStack_128 = (longlong *)0x0;
                                  plStack_130 = (longlong *)0x0;
                                  plStack_120 = (longlong *)0x0;
                                }
                                else {
                                  *(undefined4 *)(plVar3 + 5) = 0x55;
                                  plStack_120 = (longlong *)
                                                FUN_23e91bfe0(param_1,lVar10,_DAT_23eedc8b8);
                                  if (plStack_120 == (longlong *)0x0) {
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                    uVar22 = 0x55;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pcStack_138 = (code *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    plStack_130 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    *(undefined4 *)(plVar3 + 5) = 0x56;
                                    auStack_98._8_8_ = plStack_100;
                                    auStack_98._0_8_ = pcStack_118;
                                    pcStack_88 = pcStack_f8;
                                    plVar13 = (longlong *)
                                              FUN_23e9578c0(param_1,plStack_120,_DAT_23eedc8c0,
                                                            auStack_98);
                                    if (plVar13 == (longlong *)0x0) {
                                      auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                      pcStack_b0 = *(code **)(param_1 + 0x68);
                                      pcStack_a8 = *(code **)(param_1 + 0x70);
                                      uVar22 = 0x56;
                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                      pcStack_138 = (code *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0
                                      ;
                                      plStack_130 = (longlong *)0x0;
                                      goto LAB_23e889155;
                                    }
                                    lVar10 = *plVar13;
                                    *plVar13 = lVar10 + -1;
                                    if (lVar10 + -1 == 0) {
                                      FUN_23a334bc0(plVar13);
                                    }
                                    *(undefined4 *)(plVar3 + 5) = 0x57;
                                    plVar13 = (longlong *)
                                              FUN_23e915840(param_1,plStack_110,_DAT_23eedc8c8,
                                                            plStack_120);
                                    if (plVar13 != (longlong *)0x0) {
                                      lVar10 = *plVar13;
                                      *plVar13 = lVar10 + -1;
                                      if (lVar10 + -1 == 0) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      plVar13 = (longlong *)
                                                FUN_23e8bc2f0(plStack_110,_DAT_23eedc8d0);
                                      uVar18 = DAT_23eedc880;
                                      if (plVar13 == (longlong *)0x0) {
LAB_23e88a538:
                                        pcStack_a8 = *(code **)(param_1 + 0x70);
                                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_b0 = *(code **)(param_1 + 0x68);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        plVar14 = (longlong *)
                                                  FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),2);
                                        uVar5 = DAT_23eedc880;
                                        lVar21 = DAT_23eedc7f0;
                                        *plStack_100 = *plStack_100 + 1;
                                        lVar10 = *(longlong *)(lVar21 + 0x20);
                                        plVar14[3] = (longlong)plStack_100;
                                        *(longlong *)pcStack_f8 = *(longlong *)pcStack_f8 + 1;
                                        plVar14[4] = (longlong)pcStack_f8;
                                        if (*(char *)(lVar10 + 10) == '\0') {
                                          plVar15 = (longlong *)FUN_23a37a020(lVar21,_DAT_23eedc8d8)
                                          ;
                                          if (plVar15 == (longlong *)0x0) goto LAB_23e88a73e;
                                          lVar21 = *plVar15;
LAB_23e88a735:
                                          if (lVar21 == 0) goto LAB_23e88a73e;
LAB_23e88844f:
                                          plVar15 = (longlong *)FUN_23e8bc2f0(lVar21,_DAT_23eedc8e0)
                                          ;
                                          if (plVar15 != (longlong *)0x0) {
                                            *(undefined4 *)(plVar3 + 5) = 0x59;
                                            auStack_98._8_8_ = plVar14;
                                            auStack_98._0_8_ = uVar18;
                                            uStack_80 = uVar5;
                                            pcStack_88 = pcStack_118;
                                            plStack_78 = plVar15;
                                            plVar16 = (longlong *)
                                                      FUN_23e95b390(param_1,plVar13,auStack_98);
                                            *plVar13 = *plVar13 + -1;
                                            if (*plVar13 == 0) {
                                              FUN_23a334bc0(plVar13);
                                            }
                                            lVar10 = *plVar14;
                                            *plVar14 = lVar10 + -1;
                                            if (lVar10 + -1 == 0) {
                                              FUN_23a334bc0(plVar14);
                                            }
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0(plVar15);
                                            }
                                            if (plVar16 == (longlong *)0x0) goto LAB_23e88a538;
                                            lVar10 = *plVar16;
                                            *plVar16 = lVar10 + -1;
                                            if (lVar10 + -1 == 0) {
                                              FUN_23a334bc0(plVar16);
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x5b;
                                            plStack_130 = (longlong *)
                                                          FUN_23e91bfe0(param_1,plStack_120,
                                                                        _DAT_23eedc8e8);
                                            lVar10 = _DAT_23eedc8f8;
                                            if (plStack_130 == (longlong *)0x0) {
                                              auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                              pcStack_b0 = *(code **)(param_1 + 0x68);
                                              pcStack_a8 = *(code **)(param_1 + 0x70);
                                              uVar22 = 0x5b;
                                              *(undefined8 *)(param_1 + 0x70) = 0;
                                              pcStack_138 = (code *)0x0;
                                              plStack_128 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(param_1 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e889155;
                                            }
                                            *(undefined4 *)(plVar3 + 5) = 0x5c;
                                            plStack_128 = (longlong *)
                                                          FUN_23e915840(param_1,plStack_120,
                                                                        _DAT_23eedc8f0,
                                                                        *(undefined8 *)
                                                                         (lVar10 + 0x18));
                                            if (plStack_128 != (longlong *)0x0) {
                                              lVar10 = FUN_23e8db8e0();
                                              if (lVar10 == 0) {
                                                FUN_23e915740(param_1,pcVar20,_DAT_23eedc900);
                                              }
                                              else {
                                                plVar13 = (longlong *)FUN_23e8bc2f0(lVar10);
                                                if (plVar13 == (longlong *)0x0) {
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  uVar22 = 0x5e;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  pcStack_138 = (code *)0x0;
                                                  goto LAB_23e889155;
                                                }
                                                lVar10 = FUN_23e8db8e0();
                                                if (lVar10 == 0) {
                                                  FUN_23e915740(param_1,pcVar20,_DAT_23eedc900);
                                                }
                                                else {
                                                  plVar14 = (longlong *)
                                                            FUN_23e8bc2f0(lVar10,_DAT_23eedc910);
                                                  if (plVar14 != (longlong *)0x0) {
                                                    *(undefined4 *)(plVar3 + 5) = 0x5e;
                                                    auStack_98._0_8_ = plStack_128;
                                                    plStack_c8 = plVar14;
                                                    pcStack_138 = (code *)FUN_23e939900(param_1,
                                                  plVar13,auStack_98,&plStack_c8,_DAT_23eedc918);
                                                  lVar10 = *plVar13;
                                                  *plVar13 = lVar10 + -1;
                                                  if (lVar10 + -1 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                  if (pcStack_138 == (code *)0x0) {
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    goto LAB_23e88a60a;
                                                  }
                                                  lVar10 = FUN_23a38cc10(param_1,plStack_130,
                                                                         _DAT_23eedc920);
                                                  if (lVar10 == 0) {
LAB_23e88a9b7:
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar13 = (longlong *)
                                                              FUN_23e916ad0(*(undefined8 *)
                                                                             (param_1 + 0x10),3);
                                                    plVar13[3] = lVar10;
                                                    lVar10 = FUN_23a38cc10(param_1,plStack_130,
                                                                           _DAT_23eedc928);
                                                    if (lVar10 != 0) {
                                                      plVar13[4] = lVar10;
                                                      uVar18 = _DAT_23eedc938;
                                                      plVar14 = _DAT_23eedc930;
                                                      *_DAT_23eedc930 = *_DAT_23eedc930 + 1;
                                                      plVar13[5] = (longlong)plVar14;
                                                      cVar6 = FUN_23e8d9ac0(pcStack_138,uVar18,
                                                                            plVar13);
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      if (cVar6 == '\0') goto LAB_23e88a9b7;
                                                      lVar10 = FUN_23e8dbcd0();
                                                      if (lVar10 == 0) {
                                                        FUN_23e915740(param_1,pcVar20,_DAT_23eedc940
                                                                     );
                                                      }
                                                      else {
                                                        plVar13 = (longlong *)
                                                                  FUN_23e8bc2f0(lVar10,
                                                  _DAT_23eedc948);
                                                  if (plVar13 == (longlong *)0x0) {
LAB_23e88a933:
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    lVar10 = FUN_23e8dbcd0();
                                                    if (lVar10 == 0) {
                                                      FUN_23e915740(param_1,pcVar20,_DAT_23eedc940);
                                                      *plVar13 = *plVar13 + -1;
                                                      lVar10 = *plVar13;
                                                    }
                                                    else {
                                                      plVar14 = (longlong *)
                                                                FUN_23e8bc2f0(lVar10,_DAT_23eedc950)
                                                      ;
                                                      if (plVar14 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar3 + 5) = 0x60;
                                                        auStack_98._8_8_ = plVar14;
                                                        auStack_98._0_8_ = pcStack_138;
                                                        pcVar17 = (code *)FUN_23e94ed00(param_1,
                                                  plVar13,auStack_98);
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  *plVar14 = *plVar14 + -1;
                                                  if (*plVar14 == 0) {
                                                    FUN_23a334bc0(plVar14);
                                                  }
                                                  if (pcVar17 == (code *)0x0) goto LAB_23e88a933;
                                                  *(longlong *)pcStack_138 =
                                                       *(longlong *)pcStack_138 + -1;
                                                  if (*(longlong *)pcStack_138 == 0) {
                                                    FUN_23a334bc0(pcStack_138);
                                                  }
                                                  lVar10 = FUN_23e8dbf70();
                                                  pcStack_138 = pcVar17;
                                                  if (lVar10 == 0) {
                                                    FUN_23e915740(param_1,pcVar20,DAT_23eedc820);
                                                  }
                                                  else {
                                                    plVar13 = (longlong *)
                                                              FUN_23e8bc2f0(lVar10,_DAT_23eedc958);
                                                    if (plVar13 != (longlong *)0x0) {
                                                      *(undefined4 *)(plVar3 + 5) = 0x62;
                                                      plVar14 = (longlong *)
                                                                FUN_23e91bfe0(param_1,plStack_120,
                                                                              _DAT_23eedc960);
                                                      if (plVar14 == (longlong *)0x0) {
                                                        auStack_b8 = *(undefined1 (*) [8])
                                                                      (param_1 + 0x60);
                                                        pcStack_b0 = *(code **)(param_1 + 0x68);
                                                        pcStack_a8 = *(code **)(param_1 + 0x70);
                                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0(plVar13);
                                                        }
                                                        goto LAB_23e88a879;
                                                      }
                                                      *(undefined4 *)(plVar3 + 5) = 0x62;
                                                      plVar15 = (longlong *)
                                                                FUN_23e914090(param_1,plVar13);
                                                      *plVar13 = *plVar13 + -1;
                                                      if (*plVar13 == 0) {
                                                        FUN_23a334bc0(plVar13);
                                                      }
                                                      *plVar14 = *plVar14 + -1;
                                                      if (*plVar14 == 0) {
                                                        FUN_23a334bc0(plVar14);
                                                      }
                                                      if (plVar15 != (longlong *)0x0) {
                                                        *plVar15 = *plVar15 + -1;
                                                        if (*plVar15 == 0) {
                                                          FUN_23a334bc0(plVar15);
                                                        }
                                                        *(undefined4 *)(plVar3 + 5) = 99;
                                                        plVar13 = (longlong *)
                                                                  FUN_23e91bfe0(param_1,plStack_110,
                                                                                _DAT_23eedc968);
                                                        if (plVar13 == (longlong *)0x0) {
                                                          auStack_b8 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          pcStack_b0 = *(code **)(param_1 + 0x68);
                                                          pcStack_a8 = *(code **)(param_1 + 0x70);
                                                          uVar22 = 99;
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                        }
                                                        else {
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          *(undefined4 *)(plVar3 + 5) = 100;
                                                          plVar13 = (longlong *)
                                                                    FUN_23e91bfe0(param_1,
                                                  pcStack_118);
                                                  if (plVar13 == (longlong *)0x0) {
                                                    auStack_b8 = *(undefined1 (*) [8])
                                                                  (param_1 + 0x60);
                                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                                    uVar22 = 100;
                                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(param_1 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    *plVar13 = *plVar13 + -1;
                                                    if (*plVar13 == 0) {
                                                      FUN_23a334bc0(plVar13);
                                                    }
                                                    lVar10 = FUN_23e8dbf70();
                                                    if (lVar10 == 0) {
                                                      FUN_23e915740(param_1,pcVar20,DAT_23eedc820);
                                                    }
                                                    else {
                                                      plVar13 = (longlong *)
                                                                FUN_23e8bc2f0(lVar10,_DAT_23eedc970)
                                                      ;
                                                      if (plVar13 != (longlong *)0x0) {
                                                        plVar14 = (longlong *)FUN_23e8bc2f0(plVar2);
                                                        if (plVar14 == (longlong *)0x0) {
                                                          auStack_b8 = *(undefined1 (*) [8])
                                                                        (param_1 + 0x60);
                                                          pcStack_b0 = *(code **)(param_1 + 0x68);
                                                          pcStack_a8 = *(code **)(param_1 + 0x70);
                                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                                               (undefined1  [16])0x0;
                                                          *plVar13 = *plVar13 + -1;
                                                          if (*plVar13 == 0) {
                                                            FUN_23a334bc0(plVar13);
                                                          }
                                                          goto LAB_23e88a4b7;
                                                        }
                                                        *(undefined4 *)(plVar3 + 5) = 0x65;
                                                        auStack_98._8_8_ = plStack_108;
                                                        auStack_98._0_8_ = plVar14;
                                                        plVar15 = (longlong *)
                                                                  FUN_23e94ed00(param_1,plVar13,
                                                                                auStack_98);
                                                        *plVar13 = *plVar13 + -1;
                                                        if (*plVar13 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar14 = *plVar14 + -1;
                                                        if (*plVar14 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar15 != (longlong *)0x0) {
                                                          *plVar15 = *plVar15 + -1;
                                                          if (*plVar15 == 0) {
                                                            FUN_23a334bc0(plVar15);
                                                          }
                                                          FUN_23ebf6b20(*(undefined8 *)
                                                                         (param_1 + 0x38));
                                                          *(longlong *)pcVar17 =
                                                               *(longlong *)pcVar17 + 1;
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 != 0) {
                                                            *plVar11 = *plVar11 + -1;
                                                            if (*plVar11 == 0) goto LAB_23e888b30;
                                                            goto LAB_23e887c85;
                                                          }
                                                          (**(code **)(plVar9[1] + 0x30))(plVar9);
                                                          goto LAB_23e887c75;
                                                        }
                                                      }
                                                      auStack_b8 = *(undefined1 (*) [8])
                                                                    (param_1 + 0x60);
                                                      pcStack_b0 = *(code **)(param_1 + 0x68);
                                                      pcStack_a8 = *(code **)(param_1 + 0x70);
                                                      *(undefined8 *)(param_1 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(param_1 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                    }
LAB_23e88a4b7:
                                                    uVar22 = 0x65;
                                                  }
                                                  }
                                                  goto LAB_23e889155;
                                                  }
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  }
LAB_23e88a879:
                                                  uVar22 = 0x62;
                                                  goto LAB_23e889155;
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar13 = *plVar13 + -1;
                                                  lVar10 = *plVar13;
                                                  }
                                                  if (lVar10 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  }
                                                  }
                                                  uVar22 = 0x60;
                                                  goto LAB_23e889155;
                                                  }
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar13 = *plVar13 + -1;
                                                  if (*plVar13 == 0) {
                                                    FUN_23a334bc0(plVar13);
                                                  }
                                                  }
                                                  uVar22 = 0x5f;
                                                  goto LAB_23e889155;
                                                  }
                                                  pcStack_a8 = *(code **)(param_1 + 0x70);
                                                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60)
                                                  ;
                                                  pcStack_b0 = *(code **)(param_1 + 0x68);
                                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(param_1 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                lVar10 = *plVar13;
                                                *plVar13 = lVar10 + -1;
                                                if (lVar10 + -1 == 0) {
                                                  FUN_23a334bc0();
                                                }
                                              }
LAB_23e88a60a:
                                              uVar22 = 0x5e;
                                              pcStack_138 = (code *)0x0;
                                              goto LAB_23e889155;
                                            }
                                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                            pcStack_b0 = *(code **)(param_1 + 0x68);
                                            pcStack_a8 = *(code **)(param_1 + 0x70);
                                            uVar22 = 0x5c;
                                            *(undefined8 *)(param_1 + 0x70) = 0;
                                            pcStack_138 = (code *)0x0;
                                            *(undefined1 (*) [16])(param_1 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            goto LAB_23e889155;
                                          }
                                          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          pcStack_b0 = *(code **)(param_1 + 0x68);
                                          pcStack_a8 = *(code **)(param_1 + 0x70);
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          *plVar13 = *plVar13 + -1;
                                          lVar10 = *plVar13;
                                        }
                                        else {
                                          iVar7 = *(int *)(lVar10 + 0xc);
                                          if (*(int *)(lVar10 + 0xc) == 0) {
                                            *(int *)(lVar10 + 0xc) = DAT_23ec1555c;
                                            iVar7 = DAT_23ec1555c;
                                            DAT_23ec1555c = DAT_23ec1555c + 1;
                                          }
                                          if (_DAT_23ec15554 != iVar7) {
                                            _DAT_23ec15554 = iVar7;
                                            _DAT_23eede6a8 =
                                                 FUN_23e8cbd60(lVar10,_DAT_23eedc8d8,
                                                               *(undefined8 *)
                                                                (_DAT_23eedc8d8 + 0x18));
                                          }
                                          if (-1 < _DAT_23eede6a8) {
                                            lVar1 = lVar10 + 0x20 +
                                                    (1L << (*(byte *)(lVar10 + 9) & 0x3f));
                                            lVar21 = *(longlong *)
                                                      (lVar1 + 8 + _DAT_23eede6a8 * 0x10);
                                            if (lVar21 != 0) goto LAB_23e88844f;
                                            _DAT_23eede6a8 =
                                                 FUN_23e8cbd60(lVar10,_DAT_23eedc8d8,
                                                               *(undefined8 *)
                                                                (_DAT_23eedc8d8 + 0x18));
                                            if (-1 < _DAT_23eede6a8) {
                                              lVar21 = *(longlong *)
                                                        (lVar1 + 8 + _DAT_23eede6a8 * 0x10);
                                              goto LAB_23e88a735;
                                            }
                                          }
LAB_23e88a73e:
                                          plVar15 = (longlong *)
                                                    FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eedc8d8);
                                          if ((plVar15 != (longlong *)0x0) &&
                                             (lVar21 = *plVar15, lVar21 != 0)) goto LAB_23e88844f;
                                          FUN_23e915740(param_1,pcVar20,_DAT_23eedc8d8);
                                          *plVar13 = *plVar13 + -1;
                                          lVar10 = *plVar13;
                                        }
                                        if (lVar10 == 0) {
                                          FUN_23a334bc0(plVar13);
                                        }
                                        lVar10 = *plVar14;
                                        *plVar14 = lVar10 + -1;
                                        if (lVar10 + -1 == 0) {
                                          FUN_23a334bc0(plVar14);
                                        }
                                      }
                                      uVar22 = 0x59;
                                      pcStack_138 = (code *)0x0;
                                      plStack_128 = (longlong *)0x0;
                                      plStack_130 = (longlong *)0x0;
                                      goto LAB_23e889155;
                                    }
                                    auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_b0 = *(code **)(param_1 + 0x68);
                                    pcStack_a8 = *(code **)(param_1 + 0x70);
                                    uVar22 = 0x57;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    pcStack_138 = (code *)0x0;
                                    plStack_128 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    plStack_130 = (longlong *)0x0;
                                  }
                                }
                              }
                              goto LAB_23e889155;
                            }
                            pcStack_a8 = *(code **)(param_1 + 0x70);
                            auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcStack_b0 = *(code **)(param_1 + 0x68);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          uVar22 = 0x52;
                          pcStack_138 = (code *)0x0;
                          plStack_128 = (longlong *)0x0;
                          plStack_130 = (longlong *)0x0;
                          plStack_120 = (longlong *)0x0;
                          plStack_110 = (longlong *)0x0;
                          goto LAB_23e889155;
                        }
                        auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcStack_b0 = *(code **)(param_1 + 0x68);
                        pcStack_a8 = *(code **)(param_1 + 0x70);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        *plVar13 = *plVar13 + -1;
                        if (*plVar13 == 0) {
                          FUN_23a334bc0(plVar13);
                        }
                      }
                    }
                    uVar22 = 0x51;
                    pcStack_138 = (code *)0x0;
                    plStack_128 = (longlong *)0x0;
                    plStack_130 = (longlong *)0x0;
                    plStack_120 = (longlong *)0x0;
                    plStack_110 = (longlong *)0x0;
                    pcStack_118 = (code *)0x0;
                    plStack_108 = (longlong *)0x0;
                    goto LAB_23e889155;
                  }
                  auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_b0 = *(code **)(param_1 + 0x68);
                  pcStack_a8 = *(code **)(param_1 + 0x70);
                  pcStack_138 = (code *)0x0;
                  uVar22 = 0x4f;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  plStack_128 = (longlong *)0x0;
                  plStack_130 = (longlong *)0x0;
                  plStack_120 = (longlong *)0x0;
                  plStack_110 = (longlong *)0x0;
                  pcStack_118 = (code *)0x0;
                  plStack_108 = (longlong *)0x0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e889155;
                }
LAB_23e889caf:
                pcVar17 = pcStack_a8;
                pcVar20 = pcStack_b0;
                auVar23 = auStack_b8;
                pcStack_a8 = (code *)0x0;
                _auStack_b8 = (undefined1  [16])0x0;
                *plVar13 = *plVar13 + -1;
                if (*plVar13 == 0) {
                  (**(code **)(plVar13[1] + 0x30))(plVar13);
                }
                pcStack_a8 = (code *)0x0;
                auStack_b8 = (undefined1  [8])0x0;
                pcStack_b0 = (code *)0x0;
                if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
                  (**(code **)(plVar9[1] + 0x30))(plVar9);
                }
                if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                  (**(code **)(plVar12[1] + 0x30))(plVar12);
                }
                if ((plStack_140 != (longlong *)0x0) &&
                   (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
                  (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                }
              } while( true );
            }
            goto LAB_23e8895c0;
          }
          auStack_b8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_b0 = *(code **)(param_1 + 0x68);
          pcStack_a8 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          if (pcStack_a8 != (code *)0x0) {
            plVar9 = *(longlong **)(pcStack_a8 + 0x18);
            goto joined_r0x00023e888bf7;
          }
        }
      }
    }
  }
  plVar12 = (longlong *)0x0;
  plVar11 = (longlong *)0x0;
  plVar9 = (longlong *)0x0;
  pcStack_138 = (code *)0x0;
  iVar7 = 0x49;
  plStack_128 = (longlong *)0x0;
  plStack_130 = (longlong *)0x0;
  plStack_120 = (longlong *)0x0;
  plStack_110 = (longlong *)0x0;
  pcStack_118 = (code *)0x0;
  plStack_108 = (longlong *)0x0;
  pcStack_f8 = (code *)0x0;
  plStack_100 = (longlong *)0x0;
  plStack_140 = (longlong *)0x0;
  pcStack_e8 = _PyRuntime_exref;
LAB_23e88972b:
  pcVar20 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar20 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    pcVar17 = pcStack_a8;
  }
  else {
    pcVar17 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar17;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    pcVar17 = (code *)0x0;
  }
  *(longlong **)(pcVar20 + 0x18) = plVar3;
  *(longlong *)(pcVar20 + 0x10) = 0;
  *plVar3 = *plVar3 + 1;
  lVar10 = *(longlong *)(pcStack_e8 + 0x1f8);
  *(int *)(pcVar20 + 0x24) = iVar7;
  *(undefined4 *)(pcVar20 + 0x20) = 0xffffffff;
  lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
  lVar21 = *(longlong *)(pcVar20 + -8);
  plVar13 = *(longlong **)(lVar10 + 8);
  *plVar13 = (longlong)(pcVar20 + -0x10);
  *(longlong *)(pcVar20 + -0x10) = lVar10;
  *(ulonglong *)(pcVar20 + -8) = (ulonglong)((uint)lVar21 & 3) | (ulonglong)plVar13;
  *(code **)(lVar10 + 8) = pcVar20 + -0x10;
  if ((pcVar17 != (code *)0x0) &&
     (*(longlong *)pcVar17 = *(longlong *)pcVar17 + -1, *(longlong *)pcVar17 == 0)) {
    (**(code **)(*(longlong *)(pcVar17 + 8) + 0x30))();
  }
LAB_23e888d48:
  pcStack_a8 = pcVar20;
  FUN_23e8bba40(plVar3,"ooooooooooooooo",plVar2,plVar9,plVar11,plVar12,plStack_140,plStack_100,
                pcStack_f8,plStack_108,pcStack_118,plStack_110,plStack_120,plStack_130,plStack_128,
                pcStack_138,0);
  if (_DAT_23eede6b8 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23eede6b8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar10 + 0x28);
  plVar13 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar13 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar13 = *plVar13 + -1;
    if (*plVar13 == 0) {
      (**(code **)(plVar13[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  pcVar20 = pcStack_a8;
  pcVar17 = pcStack_b0;
  auVar23 = auStack_b8;
  plVar3[0xf] = 0;
  _auStack_b8 = (undefined1  [16])0x0;
  pcStack_a8 = (code *)0x0;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((plVar11 != (longlong *)0x0) && (*plVar11 = *plVar11 + -1, *plVar11 == 0)) {
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar10 = *plStack_140, *plStack_140 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_100 != (longlong *)0x0) &&
     (lVar10 = *plStack_100, *plStack_100 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_100[1] + 0x30))(plStack_100);
  }
  if ((pcStack_f8 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_f8, *(longlong *)pcStack_f8 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(*(longlong *)(pcStack_f8 + 8) + 0x30))(pcStack_f8);
  }
  if ((plStack_108 != (longlong *)0x0) &&
     (lVar10 = *plStack_108, *plStack_108 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_108[1] + 0x30))(plStack_108);
  }
  if ((pcStack_118 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar10 + -1, lVar10 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
  }
  if ((plStack_110 != (longlong *)0x0) &&
     (lVar10 = *plStack_110, *plStack_110 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_110[1] + 0x30))(plStack_110);
  }
  if ((plStack_120 != (longlong *)0x0) &&
     (lVar10 = *plStack_120, *plStack_120 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_120[1] + 0x30))(plStack_120);
  }
  if ((plStack_130 != (longlong *)0x0) &&
     (lVar10 = *plStack_130, *plStack_130 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_130[1] + 0x30))(plStack_130);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar10 = *plStack_128, *plStack_128 = lVar10 + -1, lVar10 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((pcStack_138 != (code *)0x0) &&
     (lVar10 = *(longlong *)pcStack_138, *(longlong *)pcStack_138 = lVar10 + -1, lVar10 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_138 + 8) + 0x30))();
  }
  *plVar2 = *plVar2 + -1;
  pcStack_a8 = pcVar20;
  auStack_b8 = auVar23;
  pcStack_b0 = pcVar17;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  FUN_23a33aa70(param_1,auStack_b8,pcStack_b0,pcStack_a8);
  return (code *)0x0;
}
