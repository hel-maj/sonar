/* ===== 23e7f5660 workers.fishing.memory_fish_read:241 ===== */
/* ghidra_name=FUN_23e7f5660 entry=23e7f5660 size=23856 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e7f5660(longlong param_1,undefined8 param_2,longlong *param_3)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  undefined1 auVar9 [8];
  longlong *plVar10;
  code *pcVar11;
  longlong lVar12;
  longlong *plVar13;
  code *pcVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  undefined8 *puVar19;
  longlong lVar20;
  undefined8 uVar21;
  undefined8 in_stack_fffffffffffffde8;
  undefined4 uVar22;
  longlong *plStack_198;
  longlong *plStack_190;
  longlong *plStack_188;
  longlong *plStack_178;
  longlong *plStack_170;
  code *pcStack_168;
  longlong *plStack_160;
  code *pcStack_158;
  longlong *plStack_150;
  code *pcStack_148;
  longlong *plStack_140;
  longlong *plStack_138;
  code *pcStack_130;
  longlong *plStack_128;
  code *pcStack_120;
  code *pcStack_118;
  longlong *plStack_110;
  longlong *plStack_108;
  longlong *plStack_f8;
  code *pcStack_e8;
  code *pcStack_e0;
  code *pcStack_d8;
  undefined8 uStack_c8;
  undefined8 uStack_c0;
  longlong *plStack_b8;
  undefined1 auStack_a8 [8];
  code *pcStack_a0;
  code *apcStack_98 [2];
  code *pcStack_88;
  code *pcStack_80;
  code *pcStack_78;
  
  plVar7 = _DAT_23eedea80;
  param_3 = (longlong *)*param_3;
  apcStack_98[0] = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  pcStack_a0 = (code *)0x0;
  if (_DAT_23eedea80 == (longlong *)0x0) {
LAB_23e7f56cd:
    _DAT_23eedea80 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23eedea78,DAT_23eedebc0);
  }
  else {
    lVar12 = *_DAT_23eedea80;
    if (1 < lVar12) {
      *_DAT_23eedea80 = lVar12 + -1;
      goto LAB_23e7f56cd;
    }
    if (_DAT_23eedea80[2] != 0) {
      *_DAT_23eedea80 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e7f56cd;
    }
  }
  plVar2 = _DAT_23eedea80;
  lVar12 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eedea80 + 9;
  lVar20 = *(longlong *)(lVar12 + 8);
  _DAT_23eedea80[0xf] = lVar20;
  *(longlong **)(lVar12 + 8) = plVar7;
  if ((lVar20 != 0) &&
     (((*(char *)(lVar20 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar20 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar20 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar20 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar20 = DAT_23eeddba8;
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar12 = *(longlong *)(lVar20 + 0x20);
  if (*(char *)(lVar12 + 10) == '\0') {
    plVar7 = (longlong *)FUN_23a37a020(lVar20,_DAT_23eeddf50);
    if (plVar7 == (longlong *)0x0) goto LAB_23e7f5ca9;
    lVar12 = *plVar7;
LAB_23e7f6c58:
    if (lVar12 == 0) goto LAB_23e7f5ca9;
LAB_23e7f57bd:
    *(undefined4 *)(plVar2 + 5) = 0xf2;
    plStack_190 = (longlong *)FUN_23e91a870();
    if (plStack_190 == (longlong *)0x0) {
      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcStack_a0 = *(code **)(param_1 + 0x68);
      apcStack_98[0] = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (apcStack_98[0] == (code *)0x0) goto LAB_23e7f7b78;
      if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18)) goto LAB_23e7f68e8;
      plVar8 = (longlong *)0x0;
      plStack_138 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      iVar6 = 0xf2;
      pcStack_148 = (code *)0x0;
      plStack_150 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      plStack_128 = (longlong *)0x0;
      pcStack_130 = (code *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_168 = (code *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      pcStack_120 = _PyRuntime_exref;
    }
    else {
      iVar6 = FUN_23a35f020();
      if (iVar6 == -1) {
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        if (apcStack_98[0] == (code *)0x0) {
          plVar8 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          iVar6 = 0xf3;
          pcStack_148 = (code *)0x0;
          plStack_150 = (longlong *)0x0;
          pcStack_158 = (code *)0x0;
          plStack_128 = (longlong *)0x0;
          pcStack_130 = (code *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_168 = (code *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          pcStack_120 = _PyRuntime_exref;
          goto LAB_23e7f7491;
        }
        plVar8 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        pcStack_148 = (code *)0x0;
        plStack_150 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        plStack_128 = (longlong *)0x0;
        pcStack_130 = (code *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_168 = (code *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plVar13 = plVar8;
        pcVar11 = apcStack_98[0];
        if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f6266;
        iVar6 = 0xf3;
        pcStack_120 = _PyRuntime_exref;
      }
      else {
        if (iVar6 != 0) {
          lVar12 = *(longlong *)(param_1 + 0x10);
          if (*(int *)(lVar12 + 0x1188) == 0) {
            plStack_188 = (longlong *)FUN_23a33a530(PyList_Type_exref);
          }
          else {
            iVar6 = *(int *)(lVar12 + 0x1188) + -1;
            *(int *)(lVar12 + 0x1188) = iVar6;
            plStack_188 = *(longlong **)(lVar12 + 0xf08 + (longlong)iVar6 * 8);
            *plStack_188 = 1;
          }
          pcStack_120 = _PyRuntime_exref;
          plStack_188[2] = 0;
          plStack_188[4] = 0;
          lVar12 = *(longlong *)(pcStack_120 + 0x1f8);
          plStack_188[3] = 0;
          lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
          lVar20 = plStack_188[-1];
          puVar19 = *(undefined8 **)(lVar12 + 8);
          *puVar19 = plStack_188 + -2;
          plStack_188[-2] = lVar12;
          plStack_188[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar19;
          *(longlong **)(lVar12 + 8) = plStack_188 + -2;
          plVar7 = (longlong *)FUN_23ebf7180();
          if (plVar7 == (longlong *)0x0) {
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            apcStack_98[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            plVar7 = (longlong *)0x0;
            if (apcStack_98[0] != (code *)0x0) {
              plVar15 = *(longlong **)(apcStack_98[0] + 0x18);
              iVar6 = 0xfa;
              plStack_170 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_168 = (code *)0x0;
              plStack_198 = (longlong *)0x0;
joined_r0x00023e7f7b0e:
              plVar7 = (longlong *)0x0;
              pcStack_130 = (code *)0x0;
              plStack_128 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              plStack_150 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              plStack_140 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plVar8 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              pcVar11 = apcStack_98[0];
              if (plVar15 == plVar2) goto LAB_23e7f6266;
              goto LAB_23e7f61b4;
            }
            plStack_138 = (longlong *)0x0;
            plVar8 = (longlong *)0x0;
            iVar6 = 0xfa;
            plStack_140 = (longlong *)0x0;
            pcStack_148 = (code *)0x0;
            plStack_150 = (longlong *)0x0;
            pcStack_158 = (code *)0x0;
            plStack_128 = (longlong *)0x0;
            pcStack_130 = (code *)0x0;
            plStack_170 = (longlong *)0x0;
            plStack_178 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcStack_168 = (code *)0x0;
            plStack_198 = (longlong *)0x0;
          }
          else {
            lVar12 = plVar7[1];
            if (*(code **)(lVar12 + 0xe0) == (code *)0x0) {
              plStack_170 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_168 = (code *)0x0;
              plStack_198 = (longlong *)0x0;
LAB_23e7f6c8b:
              PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,"\'%s\' object is not an iterator",
                           *(undefined8 *)(lVar12 + 0x18));
            }
            else {
              plVar8 = (longlong *)(**(code **)(lVar12 + 0xe0))(plVar7);
              if (plVar8 == (longlong *)0x0) {
                plStack_170 = (longlong *)0x0;
                plStack_178 = (longlong *)0x0;
                plStack_160 = (longlong *)0x0;
                pcStack_168 = (code *)0x0;
                plStack_198 = plVar8;
              }
              else {
                *plVar8 = *plVar8 + 1;
                plStack_170 = (longlong *)0x0;
                plStack_178 = (longlong *)0x0;
                pcVar11 = (code *)0x0;
                plStack_160 = (longlong *)0x0;
LAB_23e7f5f22:
                plVar13 = plVar8;
                lVar12 = *(longlong *)(DAT_23eeddba8 + 0x20);
                plStack_198 = plVar13;
                if (*(char *)(lVar12 + 10) == '\0') {
                  plVar8 = (longlong *)FUN_23a37a020(DAT_23eeddba8,_DAT_23eeddf58);
                  if (plVar8 == (longlong *)0x0) goto LAB_23e7f6071;
                  lVar20 = *plVar8;
LAB_23e7f6b28:
                  if (lVar20 == 0) goto LAB_23e7f6071;
                }
                else {
                  iVar6 = *(int *)(lVar12 + 0xc);
                  if (*(int *)(lVar12 + 0xc) == 0) {
                    *(int *)(lVar12 + 0xc) = DAT_23ec15618;
                    iVar6 = DAT_23ec15618;
                    DAT_23ec15618 = DAT_23ec15618 + 1;
                  }
                  if (_DAT_23ec155e4 != iVar6) {
                    _DAT_23ec155e4 = iVar6;
                    _DAT_23eedea68 =
                         FUN_23e8cbd60(lVar12,_DAT_23eeddf58,*(undefined8 *)(_DAT_23eeddf58 + 0x18))
                    ;
                  }
                  if (-1 < _DAT_23eedea68) {
                    lVar1 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                    lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedea68 * 0x10);
                    if (lVar20 != 0) goto LAB_23e7f5f93;
                    _DAT_23eedea68 =
                         FUN_23e8cbd60(lVar12,_DAT_23eeddf58,*(undefined8 *)(_DAT_23eeddf58 + 0x18))
                    ;
                    if (-1 < _DAT_23eedea68) {
                      lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedea68 * 0x10);
                      goto LAB_23e7f6b28;
                    }
                  }
LAB_23e7f6071:
                  plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddf58);
                  if ((plVar8 == (longlong *)0x0) || (lVar20 = *plVar8, lVar20 == 0)) {
                    iVar6 = 0xfb;
                    FUN_23e915740(param_1,auStack_a8,_DAT_23eeddf58);
                    pcVar18 = apcStack_98[0];
                    auVar9 = auStack_a8;
                    pcVar14 = pcStack_a0;
                    pcStack_168 = pcVar11;
                    goto LAB_23e7f60fe;
                  }
                }
LAB_23e7f5f93:
                *(undefined4 *)(plVar2 + 5) = 0xfb;
                pcStack_168 = (code *)FUN_23e914090(param_1,lVar20,plVar13);
                if (pcStack_168 == (code *)0x0) {
                  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcVar18 = *(code **)(param_1 + 0x70);
                  iVar6 = 0xfb;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar14 = *(code **)(param_1 + 0x68);
                  pcStack_168 = pcVar11;
                  goto LAB_23e7f60fe;
                }
                if ((pcVar11 != (code *)0x0) &&
                   (*(longlong *)pcVar11 = *(longlong *)pcVar11 + -1, *(longlong *)pcVar11 == 0)) {
                  (**(code **)(*(longlong *)(pcVar11 + 8) + 0x30))(pcVar11);
                }
                iVar6 = FUN_23a35f020();
                if (iVar6 == -1) {
                  pcVar18 = *(code **)(param_1 + 0x70);
                  iVar6 = 0xfc;
                  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar14 = *(code **)(param_1 + 0x68);
                  goto LAB_23e7f60fe;
                }
                plVar8 = plStack_160;
                if (iVar6 != 0) {
                  lVar12 = *(longlong *)(DAT_23eeddba8 + 0x20);
                  if (*(char *)(lVar12 + 10) == '\0') {
                    plVar8 = (longlong *)FUN_23a37a020(DAT_23eeddba8,_DAT_23eeddf60);
                    if (plVar8 == (longlong *)0x0) goto LAB_23e7f6851;
                    lVar20 = *plVar8;
LAB_23e7f7a28:
                    if (lVar20 == 0) goto LAB_23e7f6851;
LAB_23e7f671d:
                    pcVar11 = (code *)FUN_23e8dd670();
                    lVar12 = _DAT_23eeddd20;
                    if (pcVar11 != (code *)0x0) {
                      *(undefined4 *)(plVar2 + 5) = 0xfe;
                      pcStack_88 = pcStack_168;
                      pcStack_80 = pcVar11;
                      plVar8 = (longlong *)FUN_23e94ed00(param_1,lVar20,&pcStack_88);
                      if (plVar8 == (longlong *)0x0) {
                        pcVar18 = *(code **)(param_1 + 0x70);
                        iVar6 = 0xfe;
                        auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        pcVar14 = *(code **)(param_1 + 0x68);
                        goto LAB_23e7f60fe;
                      }
                      if ((plStack_160 != (longlong *)0x0) &&
                         (*plStack_160 = *plStack_160 + -1, *plStack_160 == 0)) {
                        (**(code **)(plStack_160[1] + 0x30))(plStack_160);
                      }
                      iVar6 = FUN_23a35f020();
                      plStack_160 = plVar8;
                      if (iVar6 == -1) {
                        auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                        pcVar18 = *(code **)(param_1 + 0x70);
                        iVar6 = 0xff;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                        pcVar14 = *(code **)(param_1 + 0x68);
                        goto LAB_23e7f60fe;
                      }
                      if (iVar6 == 0) {
                        lVar12 = FUN_23e8dd910();
                        if (lVar12 == 0) {
                          iVar6 = 0x103;
                          FUN_23e915740(param_1,auStack_a8,_DAT_23eeddc10);
                          pcVar18 = apcStack_98[0];
                          auVar9 = auStack_a8;
                          pcVar14 = pcStack_a0;
                          goto LAB_23e7f60fe;
                        }
                        *(undefined4 *)(plVar2 + 5) = 0x103;
                        plVar15 = (longlong *)FUN_23e915840(param_1,lVar12,_DAT_23eeddf78);
                        if (plVar15 == (longlong *)0x0) {
                          auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcVar18 = *(code **)(param_1 + 0x70);
                          iVar6 = 0x103;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pcVar14 = *(code **)(param_1 + 0x68);
                          goto LAB_23e7f60fe;
                        }
                        *plVar15 = *plVar15 + -1;
                        if (*plVar15 == 0) {
                          (**(code **)(plVar15[1] + 0x30))();
                        }
                      }
                      else {
                        plVar15 = (longlong *)FUN_23ebf7180();
                        if (plVar15 == (longlong *)0x0) {
                          auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcVar18 = *(code **)(param_1 + 0x70);
                          iVar6 = 0x100;
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          pcVar14 = *(code **)(param_1 + 0x68);
                          goto LAB_23e7f60fe;
                        }
                        plStack_160 = (longlong *)0x0;
LAB_23e7f6f20:
                        pcVar11 = *(code **)(plVar15[1] + 0xe0);
                        if (pcVar11 != (code *)0x0) {
                          plVar16 = (longlong *)(*pcVar11)(plVar15);
                          if (plVar16 == (longlong *)0x0) goto LAB_23e7f76b3;
                          if ((plStack_160 != (longlong *)0x0) &&
                             (*plStack_160 = *plStack_160 + -1, *plStack_160 == 0)) {
                            (**(code **)(plStack_160[1] + 0x30))(plStack_160);
                          }
                          plVar17 = (longlong *)FUN_23a388310();
                          plStack_160 = plVar16;
                          if (plVar17 == (longlong *)0x0) {
                            auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcVar14 = *(code **)(param_1 + 0x68);
                            pcVar18 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7f7917:
                            iVar6 = 0x100;
                          }
                          else {
                            plVar16 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                            if ((plVar16 == (longlong *)0x0) &&
                               (plVar16 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,0,2),
                               plVar16 == (longlong *)0x0)) {
                              lVar12 = *plVar17;
                              plStack_140 = (longlong *)0x0;
LAB_23e7f7881:
                              pcVar18 = apcStack_98[0];
                              pcVar14 = pcStack_a0;
                              auVar9 = auStack_a8;
                              _auStack_a8 = (undefined1  [16])0x0;
                              apcStack_98[0] = (code *)0x0;
                              *plVar17 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                (**(code **)(plVar17[1] + 0x30))();
                              }
                              apcStack_98[0] = (code *)0x0;
                              _auStack_a8 = (undefined1  [16])0x0;
                              if ((plVar16 != (longlong *)0x0) &&
                                 (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                (**(code **)(plVar16[1] + 0x30))();
                              }
                              if ((plStack_140 != (longlong *)0x0) &&
                                 (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1,
                                 lVar12 + -1 == 0)) {
                                (**(code **)(plStack_140[1] + 0x30))();
                              }
                              goto LAB_23e7f7917;
                            }
                            plStack_198 = (longlong *)auStack_a8;
                            plStack_140 = (longlong *)(**(code **)(plVar17[1] + 0xe0))(plVar17);
                            if ((plStack_140 == (longlong *)0x0) &&
                               (plStack_140 = (longlong *)FUN_23a3c1b70(param_1,plStack_198,1,2),
                               plStack_140 == (longlong *)0x0)) {
                              lVar12 = *plVar17;
                              goto LAB_23e7f7881;
                            }
                            cVar5 = FUN_23a3884a0(param_1,plStack_198,plVar17);
                            lVar12 = *plVar17;
                            if (cVar5 == '\0') goto LAB_23e7f7881;
                            *plVar17 = lVar12 + -1;
                            if (lVar12 + -1 == 0) {
                              (**(code **)(plVar17[1] + 0x30))(plVar17);
                            }
                            lVar12 = *plVar16;
                            *plVar16 = lVar12 + 1;
                            if (plStack_178 != (longlong *)0x0) {
                              *plStack_178 = *plStack_178 + -1;
                              if (*plStack_178 == 0) {
                                (**(code **)(plStack_178[1] + 0x30))(plStack_178);
                              }
                              lVar12 = *plVar16 + -1;
                            }
                            *plVar16 = lVar12;
                            if (lVar12 == 0) {
                              (**(code **)(plVar16[1] + 0x30))(plVar16);
                            }
                            lVar12 = *plStack_140;
                            *plStack_140 = lVar12 + 1;
                            if (plStack_170 != (longlong *)0x0) {
                              *plStack_170 = *plStack_170 + -1;
                              if (*plStack_170 == 0) {
                                (**(code **)(plStack_170[1] + 0x30))(plStack_170);
                              }
                              lVar12 = *plStack_140 + -1;
                            }
                            *plStack_140 = lVar12;
                            if (lVar12 == 0) {
                              (**(code **)(plStack_140[1] + 0x30))(plStack_140);
                            }
                            plVar17 = (longlong *)FUN_23e8bc2f0(plStack_188,_DAT_23eeddd18);
                            plStack_178 = plVar16;
                            plStack_170 = plStack_140;
                            if (plVar17 != (longlong *)0x0) {
                              lVar12 = *(longlong *)(param_1 + 0x10);
                              plVar10 = *(longlong **)(lVar12 + 0xe30);
                              if (plVar10 == (longlong *)0x0) {
                                plVar10 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,4);
                              }
                              else {
                                lVar20 = plVar10[3];
                                *(int *)(lVar12 + 0xec4) = *(int *)(lVar12 + 0xec4) + -1;
                                *(longlong *)(lVar12 + 0xe30) = lVar20;
                                *plVar10 = 1;
                              }
                              lVar12 = *(longlong *)
                                        (*(longlong *)(*(longlong *)(pcStack_120 + 0x1f8) + 0x10) +
                                        0x2e8);
                              lVar20 = plVar10[-1];
                              puVar19 = *(undefined8 **)(lVar12 + 8);
                              *puVar19 = plVar10 + -2;
                              plVar10[-2] = lVar12;
                              plVar10[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar19;
                              *(longlong **)(lVar12 + 8) = plVar10 + -2;
                              *plVar13 = *plVar13 + 1;
                              plVar10[3] = (longlong)plVar13;
                              *(longlong *)pcStack_168 = *(longlong *)pcStack_168 + 1;
                              plVar10[4] = (longlong)pcStack_168;
                              *plVar16 = *plVar16 + 1;
                              plVar10[5] = (longlong)plVar16;
                              *plStack_140 = *plStack_140 + 1;
                              plVar10[6] = (longlong)plStack_140;
                              *(undefined4 *)(plVar2 + 5) = 0x101;
                              plVar16 = (longlong *)FUN_23e914090(param_1,plVar17);
                              *plVar17 = *plVar17 + -1;
                              if (*plVar17 == 0) {
                                (**(code **)(plVar17[1] + 0x30))();
                              }
                              *plVar10 = *plVar10 + -1;
                              if (*plVar10 == 0) {
                                (**(code **)(plVar10[1] + 0x30))();
                              }
                              if (plVar16 == (longlong *)0x0) goto LAB_23e7f7f98;
                              *plVar16 = *plVar16 + -1;
                              if (*plVar16 == 0) {
                                (**(code **)(plVar16[1] + 0x30))();
                              }
                              lVar12 = *(longlong *)(param_1 + 0x10);
                              if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) == 0) &&
                                   (*(int *)(lVar12 + 0x78) == 0)) ||
                                  (iVar6 = Py_MakePendingCalls(), -1 < iVar6)) ||
                                 (auVar9 = *(undefined1 (*) [8])(param_1 + 0x60),
                                 auVar9 == (undefined1  [8])0x0)) goto LAB_23e7f71ad;
                              goto LAB_23e7f729f;
                            }
LAB_23e7f7f98:
                            auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                            pcVar14 = *(code **)(param_1 + 0x68);
                            iVar6 = 0x101;
                            pcVar18 = *(code **)(param_1 + 0x70);
                            *(undefined8 *)(param_1 + 0x70) = 0;
                            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          }
                          goto LAB_23e7f72f0;
                        }
                        PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                     "\'%s\' object is not an iterator",
                                     *(undefined8 *)(plVar15[1] + 0x18));
LAB_23e7f76b3:
                        cVar5 = FUN_23a3591a0();
                        if (cVar5 == '\0') {
                          auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcVar14 = *(code **)(param_1 + 0x68);
                          pcVar18 = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          apcStack_98[0] = (code *)0x0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          _auStack_a8 = (undefined1  [16])0x0;
                          if (plStack_160 == (longlong *)0x0) {
                            iVar6 = 0x100;
                          }
                          else {
                            iVar6 = 0x100;
LAB_23e7f72f0:
                            apcStack_98[0] = (code *)0x0;
                            _auStack_a8 = (undefined1  [16])0x0;
                            lVar12 = *plStack_160;
                            *plStack_160 = lVar12 + -1;
                            if (lVar12 + -1 == 0) {
                              (**(code **)(plStack_160[1] + 0x30))();
                            }
                          }
                          lVar12 = *plVar15;
                          *plVar15 = lVar12 + -1;
                          plStack_198 = plVar13;
                          plStack_160 = plVar8;
                          if (lVar12 + -1 == 0) {
                            (**(code **)(plVar15[1] + 0x30))();
                          }
                          goto LAB_23e7f60fe;
                        }
                        if ((plStack_160 != (longlong *)0x0) &&
                           (*plStack_160 = *plStack_160 + -1, *plStack_160 == 0)) {
                          (**(code **)(plStack_160[1] + 0x30))();
                        }
                        lVar12 = *plVar15;
                        *plVar15 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar15[1] + 0x30))();
                        }
                      }
                      lVar12 = *(longlong *)(param_1 + 0x10);
                      if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) == 0) &&
                           (*(int *)(lVar12 + 0x78) == 0)) ||
                          (iVar6 = Py_MakePendingCalls(), -1 < iVar6)) ||
                         (auVar9 = *(undefined1 (*) [8])(param_1 + 0x60),
                         auVar9 == (undefined1  [8])0x0)) {
                        if (*(int *)(lVar12 + 0x68) != 0) {
                          PyEval_SaveThread();
                          PyEval_AcquireThread(param_1);
                        }
                        plVar15 = *(longlong **)(param_1 + 0x90);
                        if (plVar15 == (longlong *)0x0) goto LAB_23e7f5fdf;
                        plVar16 = *(longlong **)(param_1 + 0x60);
                        plVar17 = *(longlong **)(param_1 + 0x70);
                        plVar10 = *(longlong **)(param_1 + 0x68);
                        *(longlong **)(param_1 + 0x60) = plVar15;
                        *(undefined8 *)(param_1 + 0x90) = 0;
                        *plVar15 = *plVar15 + 1;
                        *(undefined8 *)(param_1 + 0x68) = 0;
                        *(undefined8 *)(param_1 + 0x70) = 0;
                        if ((plVar16 != (longlong *)0x0) &&
                           (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                          (**(code **)(plVar16[1] + 0x30))();
                        }
                        if ((plVar10 != (longlong *)0x0) &&
                           (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
                          (**(code **)(plVar10[1] + 0x30))();
                        }
                        if ((plVar17 != (longlong *)0x0) &&
                           (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
                          (**(code **)(plVar17[1] + 0x30))();
                        }
                        auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                      }
                      pcVar18 = *(code **)(param_1 + 0x70);
                      iVar6 = 0xfa;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar14 = *(code **)(param_1 + 0x68);
                      plStack_198 = plVar13;
                      plStack_160 = plVar8;
                      goto LAB_23e7f60fe;
                    }
                  }
                  else {
                    iVar6 = *(int *)(lVar12 + 0xc);
                    if (*(int *)(lVar12 + 0xc) == 0) {
                      *(int *)(lVar12 + 0xc) = DAT_23ec15618;
                      iVar6 = DAT_23ec15618;
                      DAT_23ec15618 = DAT_23ec15618 + 1;
                    }
                    if (_DAT_23ec155e8 != iVar6) {
                      _DAT_23ec155e8 = iVar6;
                      _DAT_23eedea70 =
                           FUN_23e8cbd60(lVar12,_DAT_23eeddf60,
                                         *(undefined8 *)(_DAT_23eeddf60 + 0x18));
                    }
                    if (-1 < _DAT_23eedea70) {
                      lVar1 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
                      lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedea70 * 0x10);
                      if (lVar20 != 0) goto LAB_23e7f671d;
                      _DAT_23eedea70 =
                           FUN_23e8cbd60(lVar12,_DAT_23eeddf60,
                                         *(undefined8 *)(_DAT_23eeddf60 + 0x18));
                      if (-1 < _DAT_23eedea70) {
                        lVar20 = *(longlong *)(lVar1 + 8 + _DAT_23eedea70 * 0x10);
                        goto LAB_23e7f7a28;
                      }
                    }
LAB_23e7f6851:
                    plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddf60);
                    lVar12 = _DAT_23eeddf60;
                    if ((plVar8 != (longlong *)0x0) && (lVar20 = *plVar8, lVar20 != 0))
                    goto LAB_23e7f671d;
                  }
                  iVar6 = 0xfe;
                  FUN_23e915740(param_1,auStack_a8,lVar12);
                  pcVar18 = apcStack_98[0];
                  auVar9 = auStack_a8;
                  pcVar14 = pcStack_a0;
                  goto LAB_23e7f60fe;
                }
LAB_23e7f5fdf:
                lVar12 = plVar7[1];
                plStack_198 = plVar13;
                plStack_160 = plVar8;
                if (*(code **)(lVar12 + 0xe0) == (code *)0x0) goto LAB_23e7f6c8b;
                plVar8 = (longlong *)(**(code **)(lVar12 + 0xe0))();
                if (plVar8 != (longlong *)0x0) {
                  *plVar13 = *plVar13 + -1;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                    lVar12 = *plVar8;
                  }
                  else {
                    lVar12 = *plVar8;
                  }
                  *plVar8 = lVar12 + 1;
                  *plVar13 = *plVar13 + -1;
                  pcVar11 = pcStack_168;
                  if (*plVar13 == 0) {
                    (**(code **)(plVar13[1] + 0x30))(plVar13);
                  }
                  goto LAB_23e7f5f22;
                }
              }
            }
            cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
            if (cVar5 == '\0') {
              auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
              pcVar14 = *(code **)(param_1 + 0x68);
              pcVar18 = *(code **)(param_1 + 0x70);
              apcStack_98[0] = (code *)0x0;
              *(undefined8 *)(param_1 + 0x70) = 0;
              iVar6 = 0xfa;
              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              _auStack_a8 = (undefined1  [16])0x0;
              if (plStack_198 != (longlong *)0x0) {
LAB_23e7f60fe:
                apcStack_98[0] = (code *)0x0;
                _auStack_a8 = (undefined1  [16])0x0;
                lVar12 = *plStack_198;
                *plStack_198 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plStack_198[1] + 0x30))();
                }
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))();
              }
              apcStack_98[0] = pcVar18;
              auStack_a8 = auVar9;
              pcStack_a0 = pcVar14;
              if (pcVar18 != (code *)0x0) {
                plVar15 = *(longlong **)(pcVar18 + 0x18);
                goto joined_r0x00023e7f7b0e;
              }
              plStack_138 = (longlong *)0x0;
              plVar8 = (longlong *)0x0;
              plVar7 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              pcStack_148 = (code *)0x0;
              plStack_150 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              plStack_128 = (longlong *)0x0;
              pcStack_130 = (code *)0x0;
            }
            else {
              if ((plStack_198 != (longlong *)0x0) &&
                 (lVar12 = *plStack_198, *plStack_198 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_198[1] + 0x30))(plStack_198);
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              iVar6 = FUN_23a35f020();
              if (iVar6 == -1) {
                auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_a0 = *(code **)(param_1 + 0x68);
                apcStack_98[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (apcStack_98[0] == (code *)0x0) {
                  plVar8 = (longlong *)0x0;
                  iVar6 = 0x105;
                  plStack_138 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  pcStack_148 = (code *)0x0;
                  plStack_150 = (longlong *)0x0;
                  pcStack_158 = (code *)0x0;
                  plStack_128 = (longlong *)0x0;
                  pcStack_130 = (code *)0x0;
                  plVar7 = (longlong *)0x0;
                  goto LAB_23e7f7491;
                }
                if (*(longlong **)(apcStack_98[0] + 0x18) != plVar2) {
                  plVar8 = (longlong *)0x0;
                  plVar7 = (longlong *)0x0;
                  plStack_138 = (longlong *)0x0;
                  iVar6 = 0x105;
                  plStack_140 = (longlong *)0x0;
                  pcStack_148 = (code *)0x0;
                  plStack_150 = (longlong *)0x0;
                  pcStack_158 = (code *)0x0;
                  plStack_128 = (longlong *)0x0;
                  pcStack_130 = (code *)0x0;
                  goto LAB_23e7f61b4;
                }
LAB_23e7f8f71:
                plStack_138 = (longlong *)0x0;
                plVar7 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_148 = (code *)0x0;
                plStack_150 = (longlong *)0x0;
                pcStack_158 = (code *)0x0;
                plStack_128 = (longlong *)0x0;
                pcStack_130 = (code *)0x0;
                plVar13 = (longlong *)0x0;
                pcVar11 = apcStack_98[0];
                goto LAB_23e7f6266;
              }
              if (iVar6 == 0) {
                cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eedde90);
                if (cVar5 != '\0') {
                  plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde78);
                  if (plVar7 == (longlong *)0x0) {
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (apcStack_98[0] == (code *)0x0) {
LAB_23e7f9e14:
                      plVar8 = (longlong *)0x0;
                      plVar7 = (longlong *)0x0;
                      iVar6 = 0x107;
                      plStack_138 = (longlong *)0x0;
                      plStack_140 = (longlong *)0x0;
                      pcStack_148 = (code *)0x0;
                      plStack_150 = (longlong *)0x0;
                      pcStack_158 = (code *)0x0;
                      plStack_128 = (longlong *)0x0;
                      pcStack_130 = (code *)0x0;
                      goto LAB_23e7f7491;
                    }
                    plStack_138 = (longlong *)0x0;
                    plStack_140 = (longlong *)0x0;
                    pcStack_148 = (code *)0x0;
                    plStack_150 = (longlong *)0x0;
                    pcStack_158 = (code *)0x0;
                    plStack_128 = (longlong *)0x0;
                    pcStack_130 = (code *)0x0;
                    plVar7 = (longlong *)0x0;
                    plVar13 = (longlong *)0x0;
                    pcVar11 = apcStack_98[0];
                    if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f6266;
                  }
                  else {
                    *(undefined4 *)(plVar2 + 5) = 0x107;
                    plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eeddea0);
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))();
                    }
                    if (plVar8 != (longlong *)0x0) {
                      lVar12 = *plVar8;
                      *plVar8 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                      }
                      lVar12 = *(longlong *)_Py_NoneStruct_exref;
                      goto LAB_23e7f590b;
                    }
                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                    pcStack_a0 = *(code **)(param_1 + 0x68);
                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    if (apcStack_98[0] == (code *)0x0) goto LAB_23e7f9e14;
                    if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f8f71;
                  }
                  pcStack_130 = (code *)0x0;
                  plVar7 = (longlong *)0x0;
                  plStack_128 = (longlong *)0x0;
                  plStack_138 = (longlong *)0x0;
                  plStack_140 = (longlong *)0x0;
                  pcStack_148 = (code *)0x0;
                  plStack_150 = (longlong *)0x0;
                  pcStack_158 = (code *)0x0;
                  plVar8 = (longlong *)0x0;
                  iVar6 = 0x107;
                  goto LAB_23e7f61b4;
                }
                auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                pcStack_a0 = *(code **)(param_1 + 0x68);
                apcStack_98[0] = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                if (apcStack_98[0] != (code *)0x0) {
                  if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f8f71;
                  plVar8 = (longlong *)0x0;
                  plVar7 = (longlong *)0x0;
                  plStack_138 = (longlong *)0x0;
                  iVar6 = 0x106;
                  plStack_140 = (longlong *)0x0;
                  pcStack_148 = (code *)0x0;
                  plStack_150 = (longlong *)0x0;
                  pcStack_158 = (code *)0x0;
                  plStack_128 = (longlong *)0x0;
                  pcStack_130 = (code *)0x0;
                  goto LAB_23e7f61b4;
                }
                plVar8 = (longlong *)0x0;
                iVar6 = 0x106;
                plStack_138 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_148 = (code *)0x0;
                plStack_150 = (longlong *)0x0;
                pcStack_158 = (code *)0x0;
                plStack_128 = (longlong *)0x0;
                pcStack_130 = (code *)0x0;
                plVar7 = (longlong *)0x0;
              }
              else {
                lVar12 = FUN_23e8dd280();
                if (lVar12 == 0) {
                  FUN_23e915740(param_1,auStack_a8,_DAT_23eeddf80);
                  plVar7 = (longlong *)0x0;
                }
                else {
                  *(undefined4 *)(plVar2 + 5) = 0x10b;
                  plVar7 = (longlong *)FUN_23e914090(param_1,lVar12);
                  pcVar11 = _Py_TrueStruct_exref;
                  if (plVar7 != (longlong *)0x0) {
                    cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eedde90,_Py_TrueStruct_exref);
                    if (cVar5 == '\0') {
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      apcStack_98[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (apcStack_98[0] == (code *)0x0) {
                        plVar8 = (longlong *)0x0;
                        iVar6 = 0x10c;
                        plStack_138 = (longlong *)0x0;
                        plStack_140 = (longlong *)0x0;
                        pcStack_148 = (code *)0x0;
                        plStack_150 = (longlong *)0x0;
                        pcStack_158 = (code *)0x0;
                        plStack_128 = (longlong *)0x0;
                        pcStack_130 = (code *)0x0;
                        goto LAB_23e7f7491;
                      }
                      if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f966d;
                      plVar8 = (longlong *)0x0;
                      iVar6 = 0x10c;
                      plStack_138 = (longlong *)0x0;
                      plStack_140 = (longlong *)0x0;
                      pcStack_148 = (code *)0x0;
                      plStack_150 = (longlong *)0x0;
                      pcStack_158 = (code *)0x0;
                      plStack_128 = (longlong *)0x0;
                      pcStack_130 = (code *)0x0;
                      goto LAB_23e7f61b4;
                    }
                    plVar8 = (longlong *)FUN_23e8bc2f0();
                    if (plVar8 == (longlong *)0x0) {
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      apcStack_98[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (apcStack_98[0] == (code *)0x0) {
LAB_23e7fb0f3:
                        plVar8 = (longlong *)0x0;
                        iVar6 = 0x10d;
                        plStack_138 = (longlong *)0x0;
                        plStack_140 = (longlong *)0x0;
                        pcStack_148 = (code *)0x0;
                        plStack_150 = (longlong *)0x0;
                        pcStack_158 = (code *)0x0;
                        plStack_128 = (longlong *)0x0;
                        pcStack_130 = (code *)0x0;
                        goto LAB_23e7f7491;
                      }
                      plStack_138 = (longlong *)0x0;
                      plStack_140 = (longlong *)0x0;
                      pcStack_148 = (code *)0x0;
                      plStack_150 = (longlong *)0x0;
                      pcStack_158 = (code *)0x0;
                      plStack_128 = (longlong *)0x0;
                      pcStack_130 = (code *)0x0;
                      plVar13 = (longlong *)0x0;
                      pcVar11 = apcStack_98[0];
                      if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f6266;
                    }
                    else {
                      *(undefined4 *)(plVar2 + 5) = 0x10d;
                      plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eeddea0);
                      lVar12 = *plVar8;
                      *plVar8 = lVar12 + -1;
                      if (lVar12 + -1 == 0) {
                        (**(code **)(plVar8[1] + 0x30))();
                      }
                      if (plVar13 != (longlong *)0x0) {
                        lVar12 = *plVar13;
                        *plVar13 = lVar12 + -1;
                        if (lVar12 + -1 == 0) {
                          (**(code **)(plVar13[1] + 0x30))(plVar13);
                        }
                        if (param_3 == (longlong *)0x0) {
                          FUN_23e8ba2b0(auStack_a8,_DAT_23eeddf28);
                          if ((auStack_a8 != (undefined1  [8])_Py_NoneStruct_exref) &&
                             (auStack_a8 != (undefined1  [8])0x0)) {
                            FUN_23e91b1b0(param_1,auStack_a8,auStack_a8 + 8,apcStack_98);
                          }
                          FUN_23ebf6a40(*(undefined8 *)(param_1 + 0x138),pcStack_a0);
                          pcStack_130 = apcStack_98[0];
                          if (apcStack_98[0] == (code *)0x0) {
                            plVar8 = (longlong *)0x0;
                            plStack_138 = (longlong *)0x0;
                            plStack_140 = (longlong *)0x0;
                            pcStack_148 = (code *)0x0;
                            plStack_150 = (longlong *)0x0;
                            pcStack_158 = (code *)0x0;
                            plStack_128 = (longlong *)0x0;
                            iVar6 = 0x110;
                            goto LAB_23e7f7491;
                          }
                          if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) goto LAB_23e7f966d;
                          plVar8 = (longlong *)0x0;
                          iVar6 = 0x110;
                          plStack_138 = (longlong *)0x0;
                          plStack_140 = (longlong *)0x0;
                          pcStack_148 = (code *)0x0;
                          plStack_150 = (longlong *)0x0;
                          pcStack_158 = (code *)0x0;
                          plStack_128 = (longlong *)0x0;
                          pcStack_130 = (code *)0x0;
                        }
                        else {
                          pcStack_158 = (code *)0x0;
                          plStack_150 = (longlong *)0x0;
                          plStack_138 = (longlong *)0x0;
                          plStack_140 = (longlong *)0x0;
                          pcStack_148 = (code *)0x0;
                          pcStack_130 = (code *)0x0;
                          plStack_128 = (longlong *)0x0;
                          do {
                            plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde70);
                            if (plVar8 == (longlong *)0x0) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) {
LAB_23e7fa130:
                                plVar8 = (longlong *)0x0;
                                iVar6 = 0x110;
                                goto LAB_23e7f7491;
                              }
                              plVar8 = *(longlong **)(apcStack_98[0] + 0x18);
joined_r0x00023e7f92d9:
                              if (plVar8 == plVar2) goto LAB_23e7f92e7;
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x110;
                              goto LAB_23e7f61b4;
                            }
                            *(undefined4 *)(plVar2 + 5) = 0x110;
                            plVar13 = (longlong *)FUN_23e91bfe0(param_1,plVar8,_DAT_23eeddf40);
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              (**(code **)(plVar8[1] + 0x30))();
                            }
                            if (plVar13 == (longlong *)0x0) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] != (code *)0x0) {
                                plVar8 = *(longlong **)(apcStack_98[0] + 0x18);
                                goto joined_r0x00023e7f92d9;
                              }
                              goto LAB_23e7fa130;
                            }
                            iVar6 = FUN_23a35f020();
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))();
                            }
                            if (iVar6 == -1) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) goto LAB_23e7fa130;
                              if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2)
                              goto LAB_23e7f92e7;
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x110;
                              goto LAB_23e7f61b4;
                            }
                            pcVar14 = pcVar11;
                            if (iVar6 != 0) {
                              pcVar14 = _Py_FalseStruct_exref;
                            }
                            iVar6 = FUN_23a35f020(pcVar14);
                            if (iVar6 == 0) {
                              plVar13 = (longlong *)FUN_23ebf7180();
                              if (plVar13 != (longlong *)0x0) {
                                plStack_f8 = (longlong *)0x0;
                                plVar8 = (longlong *)0x0;
                                goto LAB_23e7fa1dc;
                              }
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) {
                                iVar6 = 0x122;
                                plVar8 = (longlong *)0x0;
                                goto LAB_23e7f7491;
                              }
                              if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18)) {
                                plVar13 = (longlong *)0x0;
                                pcVar11 = apcStack_98[0];
                                goto LAB_23e7f6266;
                              }
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x122;
                              goto LAB_23e7f61b4;
                            }
                            lVar12 = FUN_23e8dd280();
                            if (lVar12 == 0) {
                              FUN_23e915740(param_1,auStack_a8,_DAT_23eeddf80);
                              if (apcStack_98[0] == (code *)0x0) {
LAB_23e7fab4d:
                                plVar8 = (longlong *)0x0;
                                iVar6 = 0x111;
                                goto LAB_23e7f7491;
                              }
                              if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f92e7;
                              iVar6 = 0x111;
                              plVar8 = (longlong *)0x0;
                              goto LAB_23e7f61b4;
                            }
                            *(undefined4 *)(plVar2 + 5) = 0x111;
                            pcVar14 = (code *)FUN_23e914090(param_1,lVar12,plStack_188);
                            if (pcVar14 == (code *)0x0) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) goto LAB_23e7fab4d;
                              if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f92e7;
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x111;
                              goto LAB_23e7f61b4;
                            }
                            if ((pcStack_130 != (code *)0x0) &&
                               (*(longlong *)pcStack_130 = *(longlong *)pcStack_130 + -1,
                               *(longlong *)pcStack_130 == 0)) {
                              FUN_23a334bc0(pcStack_130);
                            }
                            lVar12 = *(longlong *)(param_1 + 0x10);
                            if (*(int *)(lVar12 + 0x1188) == 0) {
                              plVar8 = (longlong *)FUN_23a33a530(PyList_Type_exref);
                            }
                            else {
                              iVar6 = *(int *)(lVar12 + 0x1188) + -1;
                              *(int *)(lVar12 + 0x1188) = iVar6;
                              plVar8 = *(longlong **)(lVar12 + 0xf08 + (longlong)iVar6 * 8);
                              *plVar8 = 1;
                            }
                            plVar8[2] = 0;
                            plVar8[4] = 0;
                            lVar12 = *(longlong *)(pcStack_120 + 0x1f8);
                            plVar8[3] = 0;
                            lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
                            lVar20 = plVar8[-1];
                            puVar19 = *(undefined8 **)(lVar12 + 8);
                            *puVar19 = plVar8 + -2;
                            plVar8[-2] = lVar12;
                            plVar8[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar19;
                            *(longlong **)(lVar12 + 8) = plVar8 + -2;
                            if ((plStack_128 != (longlong *)0x0) &&
                               (*plStack_128 = *plStack_128 + -1, *plStack_128 == 0)) {
                              FUN_23a334bc0(plStack_128);
                            }
                            plVar13 = (longlong *)FUN_23e8bc2f0(pcVar14,DAT_23eeddde0);
                            pcStack_130 = pcVar14;
                            plStack_128 = plVar8;
                            if (plVar13 == (longlong *)0x0) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) {
LAB_23e7fabb1:
                                plVar8 = (longlong *)0x0;
                                iVar6 = 0x113;
                                goto LAB_23e7f7491;
                              }
                              iVar6 = 0x113;
                              plVar8 = (longlong *)0x0;
                              if (plVar2 != *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f61b4;
                              plVar13 = (longlong *)0x0;
                              pcVar11 = apcStack_98[0];
                              goto LAB_23e7f6266;
                            }
                            *(undefined4 *)(plVar2 + 5) = 0x113;
                            plVar15 = (longlong *)FUN_23e91a870(param_1,plVar13);
                            *plVar13 = *plVar13 + -1;
                            if (*plVar13 == 0) {
                              (**(code **)(plVar13[1] + 0x30))();
                            }
                            if (plVar15 == (longlong *)0x0) {
LAB_23e7f9d57:
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) goto LAB_23e7fabb1;
                              if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f92e7;
                              plVar8 = (longlong *)0x0;
                              iVar6 = 0x113;
                              goto LAB_23e7f61b4;
                            }
                            plVar13 = (longlong *)FUN_23ebf7180();
                            *plVar15 = *plVar15 + -1;
                            if (*plVar15 == 0) {
                              (**(code **)(plVar15[1] + 0x30))();
                            }
                            if (plVar13 == (longlong *)0x0) goto LAB_23e7f9d57;
                            plStack_108 = (longlong *)0x0;
LAB_23e7f8523:
                            pcVar14 = *(code **)(plVar13[1] + 0xe0);
                            if (pcVar14 != (code *)0x0) {
                              plVar15 = (longlong *)(*pcVar14)(plVar13);
                              if (plVar15 == (longlong *)0x0) goto LAB_23e7f919f;
                              if ((plStack_108 != (longlong *)0x0) &&
                                 (*plStack_108 = *plStack_108 + -1, *plStack_108 == 0)) {
                                (**(code **)(plStack_108[1] + 0x30))(plStack_108);
                              }
                              plVar16 = (longlong *)FUN_23a388310();
                              plStack_108 = plVar15;
                              if (plVar16 == (longlong *)0x0) {
                                auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcVar14 = *(code **)(param_1 + 0x68);
                                pcVar11 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7f93ca:
                                iVar6 = 0x113;
                                pcStack_118 = pcStack_158;
                              }
                              else {
                                pcStack_118 = (code *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                                if ((pcStack_118 == (code *)0x0) &&
                                   (pcStack_118 = (code *)FUN_23a3c1b70(param_1,auStack_a8,0,2),
                                   pcStack_118 == (code *)0x0)) {
                                  plVar15 = (longlong *)0x0;
                                  *plVar16 = *plVar16 + -1;
                                  pcVar11 = apcStack_98[0];
                                  auVar9 = auStack_a8;
                                  pcVar14 = pcStack_a0;
                                  if (*plVar16 != 0) goto LAB_23e7f93ca;
LAB_23e7f948e:
                                  apcStack_98[0] = (code *)0x0;
                                  _auStack_a8 = (undefined1  [16])0x0;
                                  FUN_23a334bc0();
                                  apcStack_98[0] = (code *)0x0;
                                  _auStack_a8 = (undefined1  [16])0x0;
                                  if (pcStack_118 != (code *)0x0) {
LAB_23e7f9392:
                                    apcStack_98[0] = (code *)0x0;
                                    _auStack_a8 = (undefined1  [16])0x0;
                                    lVar12 = *(longlong *)pcStack_118;
                                    *(longlong *)pcStack_118 = lVar12 + -1;
                                    if (lVar12 + -1 == 0) {
                                      FUN_23a334bc0();
                                    }
                                  }
                                  if ((plVar15 != (longlong *)0x0) &&
                                     (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                    FUN_23a334bc0();
                                  }
                                  goto LAB_23e7f93ca;
                                }
                                plVar15 = (longlong *)(**(code **)(plVar16[1] + 0xe0))(plVar16);
                                if ((plVar15 == (longlong *)0x0) &&
                                   (plVar15 = (longlong *)FUN_23a3c1b70(param_1,auStack_a8,1),
                                   plVar15 == (longlong *)0x0)) {
                                  lVar12 = *plVar16;
LAB_23e7f934a:
                                  *plVar16 = lVar12 + -1;
                                  pcVar11 = apcStack_98[0];
                                  auVar9 = auStack_a8;
                                  pcVar14 = pcStack_a0;
                                  if (lVar12 + -1 == 0) goto LAB_23e7f948e;
                                  goto LAB_23e7f9392;
                                }
                                cVar5 = FUN_23a3884a0(param_1,auStack_a8,plVar16);
                                lVar12 = *plVar16;
                                if (cVar5 == '\0') goto LAB_23e7f934a;
                                *plVar16 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                                }
                                lVar12 = *(longlong *)pcStack_118;
                                *(longlong *)pcStack_118 = lVar12 + 1;
                                if (pcStack_158 != (code *)0x0) {
                                  *(longlong *)pcStack_158 = *(longlong *)pcStack_158 + -1;
                                  if (*(longlong *)pcStack_158 == 0) {
                                    (**(code **)(*(longlong *)(pcStack_158 + 8) + 0x30))
                                              (pcStack_158);
                                  }
                                  lVar12 = *(longlong *)pcStack_118 + -1;
                                }
                                *(longlong *)pcStack_118 = lVar12;
                                if (lVar12 == 0) {
                                  (**(code **)(*(longlong *)(pcStack_118 + 8) + 0x30))(pcStack_118);
                                }
                                lVar12 = *plVar15;
                                *plVar15 = lVar12 + 1;
                                if (plStack_150 != (longlong *)0x0) {
                                  *plStack_150 = *plStack_150 + -1;
                                  if (*plStack_150 == 0) {
                                    (**(code **)(plStack_150[1] + 0x30))(plStack_150);
                                  }
                                  lVar12 = *plVar15 + -1;
                                }
                                *plVar15 = lVar12;
                                if (lVar12 == 0) {
                                  (**(code **)(plVar15[1] + 0x30))(plVar15);
                                }
                                plVar16 = (longlong *)FUN_23e8bc2f0(plVar7,DAT_23ed6ce40);
                                pcVar14 = DAT_23ed6ccf0;
                                plStack_150 = plVar15;
                                if (plVar16 == (longlong *)0x0) {
LAB_23e7f97e8:
                                  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pcVar14 = *(code **)(param_1 + 0x68);
                                  pcVar11 = *(code **)(param_1 + 0x70);
                                  iVar6 = 0x114;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  goto LAB_23e7f8ade;
                                }
                                *(undefined4 *)(plVar2 + 5) = 0x114;
                                pcStack_80 = pcVar14;
                                pcStack_88 = pcStack_118;
                                plVar17 = (longlong *)FUN_23e94ed00(param_1,plVar16);
                                *plVar16 = *plVar16 + -1;
                                if (*plVar16 == 0) {
                                  (**(code **)(plVar16[1] + 0x30))();
                                }
                                if (plVar17 == (longlong *)0x0) goto LAB_23e7f97e8;
                                iVar6 = FUN_23e97dbc0();
                                *plVar17 = *plVar17 + -1;
                                if (*plVar17 == 0) {
                                  (**(code **)(plVar17[1] + 0x30))();
                                }
                                if (iVar6 == -1) goto LAB_23e7f97e8;
                                if (iVar6 != 1) {
LAB_23e7f8715:
                                  lVar12 = *(longlong *)(param_1 + 0x10);
                                  if ((((*(int *)(*(longlong *)(lVar12 + 0x28) + 0x160) == 0) &&
                                       (*(int *)(lVar12 + 0x78) == 0)) ||
                                      (iVar6 = Py_MakePendingCalls(), -1 < iVar6)) ||
                                     (*(longlong *)(param_1 + 0x60) == 0)) goto LAB_23e7f8742;
                                  goto LAB_23e7f8aae;
                                }
                                cVar5 = FUN_23a39bc50(param_1,plVar7,pcStack_118,plVar15);
                                if (cVar5 == '\0') {
                                  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pcVar14 = *(code **)(param_1 + 0x68);
                                  pcVar11 = *(code **)(param_1 + 0x70);
                                  iVar6 = 0x115;
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                }
                                else {
                                  plVar15 = (longlong *)FUN_23e8bc2f0(pcStack_118,DAT_23ed6d020);
                                  if (plVar15 == (longlong *)0x0) {
LAB_23e7f9c41:
                                    auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcVar14 = *(code **)(param_1 + 0x68);
                                    pcVar11 = *(code **)(param_1 + 0x70);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    *(undefined4 *)(plVar2 + 5) = 0x116;
                                    plVar16 = (longlong *)FUN_23e9557e0(param_1,plVar15);
                                    *plVar15 = *plVar15 + -1;
                                    if (*plVar15 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plVar16 == (longlong *)0x0) goto LAB_23e7f9c41;
                                    plVar15 = (longlong *)FUN_23a388310();
                                    *plVar16 = *plVar16 + -1;
                                    if (*plVar16 == 0) {
                                      FUN_23a334bc0();
                                    }
                                    if (plVar15 == (longlong *)0x0) goto LAB_23e7f9c41;
                                    pcVar18 = (code *)(**(code **)(plVar15[1] + 0xe0))(plVar15);
                                    if ((pcVar18 == (code *)0x0) &&
                                       (pcVar18 = (code *)FUN_23a3c1b70(param_1,auStack_a8,0,2),
                                       pcVar18 == (code *)0x0)) {
                                      plVar16 = (longlong *)0x0;
                                      *plVar15 = *plVar15 + -1;
                                      pcVar11 = apcStack_98[0];
                                      auVar9 = auStack_a8;
                                      pcVar14 = pcStack_a0;
                                      if (*plVar15 == 0) {
LAB_23e7f999f:
                                        apcStack_98[0] = (code *)0x0;
                                        _auStack_a8 = (undefined1  [16])0x0;
                                        FUN_23a334bc0();
                                        apcStack_98[0] = (code *)0x0;
                                        _auStack_a8 = (undefined1  [16])0x0;
                                        if (pcVar18 != (code *)0x0) goto LAB_23e7f99e2;
                                        goto LAB_23e7f9a00;
                                      }
                                    }
                                    else {
                                      plVar16 = (longlong *)
                                                (**(code **)(plVar15[1] + 0xe0))(plVar15);
                                      if ((plVar16 == (longlong *)0x0) &&
                                         (plVar16 = (longlong *)
                                                    FUN_23a3c1b70(param_1,auStack_a8,1,2),
                                         plVar16 == (longlong *)0x0)) {
                                        lVar12 = *plVar15;
                                      }
                                      else {
                                        cVar5 = FUN_23a3884a0(param_1,auStack_a8,plVar15,2);
                                        lVar12 = *plVar15;
                                        if (cVar5 != '\0') {
                                          *plVar15 = lVar12 + -1;
                                          if (lVar12 + -1 == 0) {
                                            FUN_23a334bc0(plVar15);
                                          }
                                          *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                          if ((pcStack_148 != (code *)0x0) &&
                                             (lVar12 = *(longlong *)pcStack_148,
                                             *(longlong *)pcStack_148 = lVar12 + -1,
                                             lVar12 + -1 == 0)) {
                                            FUN_23a334bc0(pcStack_148);
                                          }
                                          *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                                          if (*(longlong *)pcVar18 == 0) {
                                            FUN_23a334bc0(pcVar18);
                                          }
                                          *plVar16 = *plVar16 + 1;
                                          if ((plStack_140 != (longlong *)0x0) &&
                                             (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1,
                                             lVar12 + -1 == 0)) {
                                            FUN_23a334bc0(plStack_140);
                                          }
                                          *plVar16 = *plVar16 + -1;
                                          if (*plVar16 == 0) {
                                            FUN_23a334bc0(plVar16);
                                          }
                                          plVar15 = (longlong *)
                                                    FUN_23e8bc2f0(param_3,_DAT_23eedde40);
                                          pcStack_148 = pcVar18;
                                          plStack_140 = plVar16;
                                          if (plVar15 != (longlong *)0x0) {
                                            plVar17 = (longlong *)
                                                      FUN_23e8bc2f0(plVar15,DAT_23ed6ce40);
                                            *plVar15 = *plVar15 + -1;
                                            if (*plVar15 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar17 != (longlong *)0x0) {
                                              *(undefined4 *)(plVar2 + 5) = 0x117;
                                              pcStack_88 = pcVar18;
                                              pcStack_80 = pcVar18;
                                              plVar15 = (longlong *)
                                                        FUN_23e94ed00(param_1,plVar17,&pcStack_88);
                                              *plVar17 = *plVar17 + -1;
                                              if (*plVar17 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plVar15 != (longlong *)0x0) {
                                                if ((plStack_138 != (longlong *)0x0) &&
                                                   (lVar12 = *plStack_138,
                                                   *plStack_138 = lVar12 + -1, lVar12 + -1 == 0)) {
                                                  FUN_23a334bc0(plStack_138);
                                                }
                                                lVar12 = *(longlong *)(param_1 + 0x10);
                                                puVar19 = *(undefined8 **)(lVar12 + 0xe28);
                                                if (puVar19 == (undefined8 *)0x0) {
                                                  puVar19 = (undefined8 *)
                                                            FUN_23e916a20(PyTuple_Type_exref,3);
                                                }
                                                else {
                                                  uVar21 = puVar19[3];
                                                  *(int *)(lVar12 + 0xec0) =
                                                       *(int *)(lVar12 + 0xec0) + -1;
                                                  *(undefined8 *)(lVar12 + 0xe28) = uVar21;
                                                  *puVar19 = 1;
                                                }
                                                lVar12 = *(longlong *)
                                                          (*(longlong *)
                                                            (*(longlong *)(pcStack_120 + 0x1f8) +
                                                            0x10) + 0x2e8);
                                                uVar21 = puVar19[-1];
                                                puVar4 = *(undefined8 **)(lVar12 + 8);
                                                *puVar4 = puVar19 + -2;
                                                puVar19[-2] = lVar12;
                                                puVar19[-1] = (ulonglong)((uint)uVar21 & 3) |
                                                              (ulonglong)puVar4;
                                                *(undefined8 **)(lVar12 + 8) = puVar19 + -2;
                                                *plVar15 = *plVar15 + 1;
                                                puVar19[3] = plVar15;
                                                *(longlong *)pcVar18 = *(longlong *)pcVar18 + 1;
                                                puVar19[4] = pcVar18;
                                                *plVar16 = *plVar16 + 1;
                                                puVar19[5] = plVar16;
                                                FUN_23e8ba4b0();
                                                plStack_138 = plVar15;
                                                goto LAB_23e7f8715;
                                              }
                                            }
                                          }
                                          auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                          pcVar14 = *(code **)(param_1 + 0x68);
                                          pcVar11 = *(code **)(param_1 + 0x70);
                                          iVar6 = 0x117;
                                          *(undefined8 *)(param_1 + 0x70) = 0;
                                          *(undefined1 (*) [16])(param_1 + 0x60) =
                                               (undefined1  [16])0x0;
                                          goto LAB_23e7f8ade;
                                        }
                                      }
                                      *plVar15 = lVar12 + -1;
                                      pcVar11 = apcStack_98[0];
                                      auVar9 = auStack_a8;
                                      pcVar14 = pcStack_a0;
                                      if (lVar12 + -1 == 0) goto LAB_23e7f999f;
LAB_23e7f99e2:
                                      apcStack_98[0] = (code *)0x0;
                                      _auStack_a8 = (undefined1  [16])0x0;
                                      *(longlong *)pcVar18 = *(longlong *)pcVar18 + -1;
                                      if (*(longlong *)pcVar18 == 0) {
                                        FUN_23a334bc0();
                                      }
LAB_23e7f9a00:
                                      if ((plVar16 != (longlong *)0x0) &&
                                         (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                  }
                                  iVar6 = 0x116;
                                }
                              }
                              goto LAB_23e7f8ade;
                            }
                            PyErr_Format(*(undefined8 *)PyExc_TypeError_exref,
                                         "\'%s\' object is not an iterator",
                                         *(undefined8 *)(plVar13[1] + 0x18));
LAB_23e7f919f:
                            cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
                            if (cVar5 == '\0') {
                              auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcVar14 = *(code **)(param_1 + 0x68);
                              pcVar11 = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              apcStack_98[0] = (code *)0x0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              _auStack_a8 = (undefined1  [16])0x0;
                              if (plStack_108 == (longlong *)0x0) {
                                iVar6 = 0x113;
                              }
                              else {
                                iVar6 = 0x113;
                                pcStack_118 = pcStack_158;
LAB_23e7f8ade:
                                apcStack_98[0] = (code *)0x0;
                                _auStack_a8 = (undefined1  [16])0x0;
                                lVar12 = *plStack_108;
                                *plStack_108 = lVar12 + -1;
                                if (lVar12 + -1 == 0) {
                                  FUN_23a334bc0();
                                }
                                pcStack_158 = pcStack_118;
                              }
                              lVar12 = *plVar13;
                              *plVar13 = lVar12 + -1;
                              if (lVar12 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              plVar8 = (longlong *)0x0;
                              apcStack_98[0] = pcVar11;
                              auStack_a8 = auVar9;
                              pcStack_a0 = pcVar14;
                              if (pcVar11 == (code *)0x0) goto LAB_23e7f7491;
                              if (*(longlong **)(pcVar11 + 0x18) == plVar2) goto LAB_23e7f92e7;
                              plVar8 = (longlong *)0x0;
                              goto LAB_23e7f61b4;
                            }
                            if ((plStack_108 != (longlong *)0x0) &&
                               (*plStack_108 = *plStack_108 + -1, *plStack_108 == 0)) {
                              FUN_23a334bc0(plStack_108);
                            }
                            lVar12 = *plVar13;
                            *plVar13 = lVar12 + -1;
                            if (lVar12 + -1 == 0) {
                              FUN_23a334bc0(plVar13);
                            }
                            iVar6 = FUN_23a35f020();
                            if (iVar6 == -1) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              if (apcStack_98[0] == (code *)0x0) {
                                iVar6 = 0x11a;
                                plVar8 = (longlong *)0x0;
                                goto LAB_23e7f7491;
                              }
                              if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f92e7;
                              iVar6 = 0x11a;
                              plVar8 = (longlong *)0x0;
                              goto LAB_23e7f61b4;
                            }
                            if (iVar6 != 0) {
                              plVar13 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde58);
                              if (plVar13 == (longlong *)0x0) {
                                auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                pcVar14 = *(code **)(param_1 + 0x68);
                                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                iVar6 = 0x11b;
                                pcVar11 = *(code **)(param_1 + 0x70);
                                *(undefined8 *)(param_1 + 0x70) = 0;
                              }
                              else {
                                plVar15 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd90);
                                if (plVar15 == (longlong *)0x0) {
LAB_23e7fa7cf:
                                  pcVar11 = *(code **)(param_1 + 0x70);
                                  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
                                  pcVar14 = *(code **)(param_1 + 0x68);
                                  *(undefined8 *)(param_1 + 0x70) = 0;
                                  iVar6 = 0x11b;
                                  lVar12 = *plVar13;
                                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  *plVar13 = lVar12 + -1;
                                  if (lVar12 + -1 != 0) goto LAB_23e7fa798;
                                  plVar15 = (longlong *)0x0;
                                  pcStack_118 = (code *)0x0;
LAB_23e7fa849:
                                  pcStack_a0 = (code *)0x0;
                                  auStack_a8 = (undefined1  [8])0x0;
                                  apcStack_98[0] = (code *)0x0;
                                  FUN_23a334bc0();
                                  if (pcStack_118 != (code *)0x0) goto LAB_23e7fa761;
                                }
                                else {
                                  *(undefined4 *)(plVar2 + 5) = 0x11b;
                                  pcStack_118 = (code *)FUN_23e91a870(param_1,plVar15);
                                  *plVar15 = *plVar15 + -1;
                                  if (*plVar15 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (pcStack_118 == (code *)0x0) goto LAB_23e7fa7cf;
                                  plVar15 = (longlong *)FUN_23e8d9880(plVar13,DAT_23ed6cd98);
                                  if (plVar15 == (longlong *)0x0) {
LAB_23e7faa47:
                                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_a0 = *(code **)(param_1 + 0x68);
                                    apcStack_98[0] = *(code **)(param_1 + 0x70);
                                    iVar6 = 0x11b;
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else {
                                    plVar16 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde60);
                                    if (plVar16 != (longlong *)0x0) {
                                      plVar17 = (longlong *)FUN_23e8bc2f0(plVar16,_DAT_23eeddfa0);
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar17 == (longlong *)0x0) goto LAB_23e7fa4f0;
                                      *(undefined4 *)(plVar2 + 5) = 0x11c;
                                      plVar8 = (longlong *)FUN_23e914090(param_1,plVar17,plVar8);
                                      *plVar17 = *plVar17 + -1;
                                      if (*plVar17 == 0) {
                                        FUN_23a334bc0(plVar17);
                                      }
                                      if (plVar8 == (longlong *)0x0) goto LAB_23e7fa4f0;
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      plVar8 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde80);
                                      if (plVar8 == (longlong *)0x0) {
LAB_23e7fab96:
                                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_a0 = *(code **)(param_1 + 0x68);
                                        plVar8 = *(longlong **)(param_1 + 0x70);
                                        uVar21 = 0x11d;
                                        goto LAB_23e7fa506;
                                      }
                                      *(undefined4 *)(plVar2 + 5) = 0x11d;
                                      plVar16 = (longlong *)
                                                FUN_23e91bfe0(param_1,plVar8,_DAT_23eeddea0);
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0(plVar8);
                                      }
                                      if (plVar16 == (longlong *)0x0) goto LAB_23e7fab96;
                                      *plVar16 = *plVar16 + -1;
                                      if (*plVar16 == 0) {
                                        FUN_23a334bc0(plVar16);
                                      }
                                      *(undefined4 *)(plVar2 + 5) = 0x11b;
                                      plVar8 = (longlong *)
                                               FUN_23e957a30(param_1,plVar15,DAT_23eedde28);
                                      if (plVar8 == (longlong *)0x0) goto LAB_23e7faa47;
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0();
                                      }
LAB_23e7fa028:
                                      *plVar13 = *plVar13 + -1;
                                      if (*plVar13 == 0) {
                                        FUN_23a334bc0(plVar13);
                                      }
                                      *(longlong *)pcStack_118 = *(longlong *)pcStack_118 + -1;
                                      if (*(longlong *)pcStack_118 == 0) {
                                        FUN_23a334bc0(pcStack_118);
                                      }
                                      *plVar15 = *plVar15 + -1;
                                      if (*plVar15 == 0) {
                                        FUN_23a334bc0(plVar15);
                                      }
                                      goto LAB_23e7f920f;
                                    }
LAB_23e7fa4f0:
                                    auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                    pcStack_a0 = *(code **)(param_1 + 0x68);
                                    plVar8 = *(longlong **)(param_1 + 0x70);
                                    uVar21 = 0x11c;
LAB_23e7fa506:
                                    plVar16 = *(longlong **)(param_1 + 0x138);
                                    *(undefined8 *)(param_1 + 0x70) = 0;
                                    apcStack_98[0] = (code *)0x0;
                                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                                    uStack_c8 = auStack_a8;
                                    uStack_c0 = pcStack_a0;
                                    auStack_a8 = (undefined1  [8])0x0;
                                    pcStack_a0 = (code *)0x0;
                                    if (plVar16 != (longlong *)0x0) {
                                      *plVar16 = *plVar16 + 1;
                                    }
                                    plStack_b8 = plVar8;
                                    if (plVar8 == (longlong *)0x0) {
                                      lVar12 = FUN_23e8d6280(plVar2,uVar21);
                                    }
                                    else {
                                      lVar12 = FUN_23e8d6280(plVar2,uVar21);
                                      *(longlong **)(lVar12 + 0x10) = plVar8;
                                      *plVar8 = *plVar8 + 1;
                                    }
                                    if ((plStack_b8 != (longlong *)0x0) &&
                                       (*plStack_b8 = *plStack_b8 + -1, *plStack_b8 == 0)) {
                                      FUN_23a334bc0();
                                    }
                                    plStack_b8 = (longlong *)lVar12;
                                    FUN_23a35ef40(param_1,&uStack_c8);
                                    iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)
                                                                   (*(longlong *)(param_1 + 0x138) +
                                                                   8),
                                                          *(undefined8 *)PyExc_BaseException_exref);
                                    if (iVar6 == 0) {
                                      cVar5 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),
                                                            auStack_a8);
                                      pcVar14 = apcStack_98[0];
                                      pcVar11 = pcStack_a0;
                                      auVar9 = auStack_a8;
                                      iVar6 = 0;
                                      if (cVar5 == '\0') {
                                        iVar6 = 0x11b;
                                      }
                                      if ((apcStack_98[0] != (code *)0x0) &&
                                         (*(longlong **)(apcStack_98[0] + 0x18) == plVar2)) {
                                        *(undefined4 *)(plVar2 + 5) =
                                             *(undefined4 *)(apcStack_98[0] + 0x24);
                                      }
                                      apcStack_98[0] = (code *)0x0;
                                      _auStack_a8 = (undefined1  [16])0x0;
                                      FUN_23ebf6ae0(param_1,plVar16);
                                      pcStack_88 = (code *)auVar9;
                                      pcStack_80 = pcVar11;
                                      pcStack_78 = pcVar14;
                                      *(undefined4 *)(plVar2 + 5) = 0x11b;
                                      apcStack_98[0] = (code *)0x0;
                                      _auStack_a8 = (undefined1  [16])0x0;
                                      plVar8 = (longlong *)FUN_23e957a30(param_1,plVar15);
                                      if (plVar8 == (longlong *)0x0) {
                                        apcStack_98[0] = *(code **)(param_1 + 0x70);
                                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_a0 = *(code **)(param_1 + 0x68);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        iVar6 = 0x11b;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                        FUN_23a35d6b0();
                                        goto LAB_23e7fa72f;
                                      }
                                      *plVar8 = *plVar8 + -1;
                                      if (*plVar8 == 0) {
                                        FUN_23a334bc0();
                                      }
                                    }
                                    else {
                                      pcStack_80 = *(code **)(param_1 + 0x138);
                                      pcStack_88 = *(code **)(pcStack_80 + 8);
                                      pcStack_78 = *(code **)(pcStack_80 + 0x28);
                                      if (*(code **)(pcStack_80 + 0x28) == (code *)0x0) {
                                        pcStack_78 = _Py_NoneStruct_exref;
                                      }
                                      *(undefined4 *)(plVar2 + 5) = 0x11b;
                                      plVar8 = (longlong *)
                                               FUN_23e956150(param_1,plVar15,&pcStack_88);
                                      if (plVar8 == (longlong *)0x0) {
LAB_23e7fa67e:
                                        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                                        pcStack_a0 = *(code **)(param_1 + 0x68);
                                        pcVar11 = *(code **)(param_1 + 0x70);
                                        *(undefined8 *)(param_1 + 0x70) = 0;
                                        iVar6 = 0x11b;
                                        *(undefined1 (*) [16])(param_1 + 0x60) =
                                             (undefined1  [16])0x0;
                                      }
                                      else {
                                        iVar6 = FUN_23a35f020(plVar8);
                                        *plVar8 = *plVar8 + -1;
                                        if (*plVar8 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (iVar6 == -1) goto LAB_23e7fa67e;
                                        if (iVar6 != 0) {
                                          FUN_23ebf6ae0(param_1,plVar16);
                                          goto LAB_23e7fa028;
                                        }
                                        cVar5 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),
                                                              auStack_a8);
                                        iVar6 = 0;
                                        if (cVar5 == '\0') {
                                          iVar6 = 0x11b;
                                        }
                                        pcVar11 = apcStack_98[0];
                                        if ((apcStack_98[0] != (code *)0x0) &&
                                           (*(longlong **)(apcStack_98[0] + 0x18) == plVar2)) {
                                          *(undefined4 *)(plVar2 + 5) =
                                               *(undefined4 *)(apcStack_98[0] + 0x24);
                                        }
                                      }
                                      pcVar14 = pcStack_a0;
                                      auVar9 = auStack_a8;
                                      apcStack_98[0] = (code *)0x0;
                                      _auStack_a8 = (undefined1  [16])0x0;
                                      FUN_23ebf6ae0(param_1,plVar16);
                                      pcStack_88 = (code *)auVar9;
                                      pcStack_80 = pcVar14;
                                      pcStack_78 = pcVar11;
                                    }
                                    apcStack_98[0] = pcStack_78;
                                    auStack_a8 = (undefined1  [8])pcStack_88;
                                    pcStack_a0 = pcStack_80;
                                  }
LAB_23e7fa72f:
                                  pcVar11 = apcStack_98[0];
                                  pcVar14 = pcStack_a0;
                                  auVar9 = auStack_a8;
                                  auStack_a8 = (undefined1  [8])0x0;
                                  pcStack_a0 = (code *)0x0;
                                  apcStack_98[0] = (code *)0x0;
                                  *plVar13 = *plVar13 + -1;
                                  if (*plVar13 == 0) goto LAB_23e7fa849;
LAB_23e7fa761:
                                  lVar12 = *(longlong *)pcStack_118;
                                  *(longlong *)pcStack_118 = lVar12 + -1;
                                  if (lVar12 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                }
                                if ((plVar15 != (longlong *)0x0) &&
                                   (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
                                  FUN_23a334bc0();
                                }
                              }
LAB_23e7fa798:
                              plVar8 = (longlong *)0x0;
                              goto LAB_23e7fa79a;
                            }
LAB_23e7f920f:
                            lVar12 = FUN_23e8dd3d0();
                            if (lVar12 == 0) {
                              FUN_23e915740(param_1,auStack_a8,_DAT_23eeddf18);
joined_r0x00023e7facb6:
                              plVar8 = (longlong *)0x0;
                              if (apcStack_98[0] == (code *)0x0) {
                                plVar8 = (longlong *)0x0;
                                iVar6 = 0x11f;
                                goto LAB_23e7f7491;
                              }
                              iVar6 = 0x11f;
                              if (plVar2 != *(longlong **)(apcStack_98[0] + 0x18))
                              goto LAB_23e7f61b4;
                              plVar13 = (longlong *)0x0;
                              pcVar11 = apcStack_98[0];
                              goto LAB_23e7f6266;
                            }
                            *(undefined4 *)(plVar2 + 5) = 0x11f;
                            plVar8 = (longlong *)FUN_23e915840(param_1,lVar12,_DAT_23eeddfa8);
                            if (plVar8 == (longlong *)0x0) {
                              auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                              pcStack_a0 = *(code **)(param_1 + 0x68);
                              apcStack_98[0] = *(code **)(param_1 + 0x70);
                              *(undefined8 *)(param_1 + 0x70) = 0;
                              *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                              goto joined_r0x00023e7facb6;
                            }
                            *plVar8 = *plVar8 + -1;
                            if (*plVar8 == 0) {
                              FUN_23a334bc0(plVar8);
                            }
                            cVar5 = FUN_23a3a5fe0();
                          } while (cVar5 != '\0');
                          auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                          pcStack_a0 = *(code **)(param_1 + 0x68);
                          apcStack_98[0] = *(code **)(param_1 + 0x70);
                          *(undefined8 *)(param_1 + 0x70) = 0;
                          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                          if (apcStack_98[0] == (code *)0x0) {
                            iVar6 = 0x110;
                            plVar8 = (longlong *)0x0;
                            goto LAB_23e7f7491;
                          }
                          if (plVar2 == *(longlong **)(apcStack_98[0] + 0x18)) {
LAB_23e7f92e7:
                            plVar13 = (longlong *)0x0;
                            pcVar11 = apcStack_98[0];
                            goto LAB_23e7f6266;
                          }
                          iVar6 = 0x110;
                          plVar8 = (longlong *)0x0;
                        }
                        goto LAB_23e7f61b4;
                      }
                      auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                      pcStack_a0 = *(code **)(param_1 + 0x68);
                      apcStack_98[0] = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      if (apcStack_98[0] == (code *)0x0) goto LAB_23e7fb0f3;
                      if (*(longlong **)(apcStack_98[0] + 0x18) == plVar2) {
LAB_23e7f966d:
                        plStack_138 = (longlong *)0x0;
                        plStack_140 = (longlong *)0x0;
                        pcStack_148 = (code *)0x0;
                        plStack_150 = (longlong *)0x0;
                        pcStack_158 = (code *)0x0;
                        plStack_128 = (longlong *)0x0;
                        pcStack_130 = (code *)0x0;
                        plVar13 = (longlong *)0x0;
                        pcVar11 = apcStack_98[0];
                        goto LAB_23e7f6266;
                      }
                    }
                    plStack_128 = (longlong *)0x0;
                    pcStack_130 = (code *)0x0;
                    plStack_138 = (longlong *)0x0;
                    plStack_140 = (longlong *)0x0;
                    pcStack_148 = (code *)0x0;
                    plStack_150 = (longlong *)0x0;
                    pcStack_158 = (code *)0x0;
                    plVar8 = (longlong *)0x0;
                    iVar6 = 0x10d;
                    goto LAB_23e7f61b4;
                  }
                  auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
                  pcStack_a0 = *(code **)(param_1 + 0x68);
                  apcStack_98[0] = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                if (apcStack_98[0] != (code *)0x0) {
                  if (*(longlong **)(apcStack_98[0] + 0x18) != plVar2) {
                    plVar8 = (longlong *)0x0;
                    iVar6 = 0x10b;
                    plStack_138 = (longlong *)0x0;
                    plStack_140 = (longlong *)0x0;
                    pcStack_148 = (code *)0x0;
                    plStack_150 = (longlong *)0x0;
                    pcStack_158 = (code *)0x0;
                    plStack_128 = (longlong *)0x0;
                    pcStack_130 = (code *)0x0;
                    goto LAB_23e7f61b4;
                  }
                  goto LAB_23e7f8f71;
                }
                plVar8 = (longlong *)0x0;
                plVar7 = (longlong *)0x0;
                iVar6 = 0x10b;
                plStack_138 = (longlong *)0x0;
                plStack_140 = (longlong *)0x0;
                pcStack_148 = (code *)0x0;
                plStack_150 = (longlong *)0x0;
                pcStack_158 = (code *)0x0;
                plStack_128 = (longlong *)0x0;
                pcStack_130 = (code *)0x0;
              }
            }
          }
          goto LAB_23e7f7491;
        }
        cVar5 = FUN_23e8d9ac0(param_3,_DAT_23eedde90,_Py_FalseStruct_exref);
        if (cVar5 == '\0') {
          auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
          pcStack_a0 = *(code **)(param_1 + 0x68);
          pcVar11 = *(code **)(param_1 + 0x70);
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          apcStack_98[0] = pcVar11;
          if (pcVar11 == (code *)0x0) {
            plVar8 = (longlong *)0x0;
            plStack_138 = (longlong *)0x0;
            plVar7 = (longlong *)0x0;
            plStack_140 = (longlong *)0x0;
            iVar6 = 0xf4;
            pcStack_148 = (code *)0x0;
            plStack_150 = (longlong *)0x0;
            pcStack_158 = (code *)0x0;
            plStack_128 = (longlong *)0x0;
            pcStack_130 = (code *)0x0;
            plStack_170 = (longlong *)0x0;
            plStack_178 = (longlong *)0x0;
            plStack_160 = (longlong *)0x0;
            pcStack_168 = (code *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_188 = (longlong *)0x0;
            pcStack_120 = _PyRuntime_exref;
            goto LAB_23e7f7491;
          }
          plVar8 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          plStack_150 = (longlong *)0x0;
          pcStack_158 = (code *)0x0;
          plStack_128 = (longlong *)0x0;
          pcStack_130 = (code *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_168 = (code *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_188 = (longlong *)0x0;
          plVar13 = plVar8;
          if (*(longlong **)(pcVar11 + 0x18) == plVar2) goto LAB_23e7f6266;
          iVar6 = 0xf4;
          pcStack_120 = _PyRuntime_exref;
        }
        else {
          plVar7 = (longlong *)FUN_23e8bc2f0(param_3,_DAT_23eedde78);
          if (plVar7 == (longlong *)0x0) {
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            apcStack_98[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_98[0] == (code *)0x0) {
LAB_23e7f8770:
              pcStack_120 = _PyRuntime_exref;
              plVar8 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plVar7 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              iVar6 = 0xf5;
              pcStack_148 = (code *)0x0;
              plStack_150 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              plStack_128 = (longlong *)0x0;
              pcStack_130 = (code *)0x0;
              plStack_170 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              pcStack_168 = (code *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_188 = (longlong *)0x0;
              goto LAB_23e7f7491;
            }
            plVar8 = *(longlong **)(apcStack_98[0] + 0x18);
          }
          else {
            *(undefined4 *)(plVar2 + 5) = 0xf5;
            plVar8 = (longlong *)FUN_23e91bfe0(param_1,plVar7,_DAT_23eeddea0);
            lVar12 = *plVar7;
            *plVar7 = lVar12 + -1;
            if (lVar12 + -1 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
            if (plVar8 != (longlong *)0x0) {
              lVar12 = *plVar8;
              *plVar8 = lVar12 + -1;
              if (lVar12 + -1 == 0) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              plStack_170 = (longlong *)0x0;
              plStack_178 = (longlong *)0x0;
              plStack_160 = (longlong *)0x0;
              lVar12 = *(longlong *)_Py_NoneStruct_exref;
              pcStack_168 = (code *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_188 = (longlong *)0x0;
LAB_23e7f590b:
              pcVar11 = _Py_NoneStruct_exref;
              *(longlong *)_Py_NoneStruct_exref = lVar12 + 1;
              lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
              plVar7 = *(longlong **)(lVar12 + 0x28);
              plVar2 = (longlong *)plVar7[2];
              *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
              *(undefined4 *)(plVar7 + 8) = 0xffffffff;
              if (plVar2 != (longlong *)0x0) {
                plVar7[2] = 0;
                *plVar2 = *plVar2 + -1;
                if (*plVar2 == 0) {
                  (**(code **)(plVar2[1] + 0x30))();
                }
              }
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7[0xf] = 0;
              plStack_128 = (longlong *)0x0;
              plVar7 = (longlong *)0x0;
              plStack_138 = (longlong *)0x0;
              plStack_140 = (longlong *)0x0;
              lVar12 = *plStack_190;
              pcStack_148 = (code *)0x0;
              *plStack_190 = lVar12 + -1;
              plVar8 = (longlong *)0x0;
              plStack_150 = (longlong *)0x0;
              pcStack_158 = (code *)0x0;
              pcStack_130 = (code *)0x0;
              if (lVar12 + -1 == 0) {
LAB_23e7f59d4:
                (**(code **)(plStack_190[1] + 0x30))();
              }
              if (plStack_188 != (longlong *)0x0) {
LAB_23e7f59ee:
                lVar12 = *plStack_188;
                *plStack_188 = lVar12 + -1;
                if (lVar12 + -1 == 0) {
                  (**(code **)(plStack_188[1] + 0x30))(plStack_188);
                }
              }
              if ((plStack_198 != (longlong *)0x0) &&
                 (lVar12 = *plStack_198, *plStack_198 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_198[1] + 0x30))(plStack_198);
              }
              if ((pcStack_168 != (code *)0x0) &&
                 (lVar12 = *(longlong *)pcStack_168, *(longlong *)pcStack_168 = lVar12 + -1,
                 lVar12 + -1 == 0)) {
                (**(code **)(*(longlong *)(pcStack_168 + 8) + 0x30))(pcStack_168);
              }
              if ((plStack_160 != (longlong *)0x0) &&
                 (lVar12 = *plStack_160, *plStack_160 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_160[1] + 0x30))(plStack_160);
              }
              if ((plStack_178 != (longlong *)0x0) &&
                 (lVar12 = *plStack_178, *plStack_178 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_178[1] + 0x30))(plStack_178);
              }
              if ((plStack_170 != (longlong *)0x0) &&
                 (lVar12 = *plStack_170, *plStack_170 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_170[1] + 0x30))(plStack_170);
              }
              if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              if ((pcStack_130 != (code *)0x0) &&
                 (lVar12 = *(longlong *)pcStack_130, *(longlong *)pcStack_130 = lVar12 + -1,
                 lVar12 + -1 == 0)) {
                (**(code **)(*(longlong *)(pcStack_130 + 8) + 0x30))(pcStack_130);
              }
              if ((plStack_128 != (longlong *)0x0) &&
                 (*plStack_128 = *plStack_128 + -1, *plStack_128 == 0)) {
                (**(code **)(plStack_128[1] + 0x30))(plStack_128);
              }
              if ((pcStack_158 != (code *)0x0) &&
                 (lVar12 = *(longlong *)pcStack_158, *(longlong *)pcStack_158 = lVar12 + -1,
                 lVar12 + -1 == 0)) {
                (**(code **)(*(longlong *)(pcStack_158 + 8) + 0x30))(pcStack_158);
              }
              if ((plStack_150 != (longlong *)0x0) &&
                 (lVar12 = *plStack_150, *plStack_150 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_150[1] + 0x30))(plStack_150);
              }
              if ((pcStack_148 != (code *)0x0) &&
                 (lVar12 = *(longlong *)pcStack_148, *(longlong *)pcStack_148 = lVar12 + -1,
                 lVar12 + -1 == 0)) {
                (**(code **)(*(longlong *)(pcStack_148 + 8) + 0x30))(pcStack_148);
              }
              if ((plStack_140 != (longlong *)0x0) &&
                 (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_140[1] + 0x30))(plStack_140);
              }
              if ((plStack_138 != (longlong *)0x0) &&
                 (lVar12 = *plStack_138, *plStack_138 = lVar12 + -1, lVar12 + -1 == 0)) {
                (**(code **)(plStack_138[1] + 0x30))(plStack_138);
              }
              if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
                (**(code **)(plVar8[1] + 0x30))(plVar8);
              }
              lVar12 = *param_3;
              *param_3 = lVar12 + -1;
              if (lVar12 + -1 != 0) {
                return pcVar11;
              }
              (**(code **)(param_3[1] + 0x30))(param_3);
              return pcVar11;
            }
            auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
            pcStack_a0 = *(code **)(param_1 + 0x68);
            apcStack_98[0] = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (apcStack_98[0] == (code *)0x0) goto LAB_23e7f8770;
            plVar8 = *(longlong **)(apcStack_98[0] + 0x18);
          }
          plStack_188 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          pcStack_168 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plStack_170 = (longlong *)0x0;
          pcStack_158 = (code *)0x0;
          plStack_150 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          plStack_140 = (longlong *)0x0;
          plStack_138 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          plVar13 = (longlong *)0x0;
          pcStack_130 = (code *)0x0;
          plStack_128 = (longlong *)0x0;
          pcVar11 = apcStack_98[0];
          if (plVar2 == plVar8) goto LAB_23e7f6266;
          plStack_188 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_128 = (longlong *)0x0;
          pcStack_130 = (code *)0x0;
          plStack_138 = (longlong *)0x0;
          plStack_140 = (longlong *)0x0;
          pcStack_148 = (code *)0x0;
          plStack_150 = (longlong *)0x0;
          pcStack_158 = (code *)0x0;
          plStack_160 = (longlong *)0x0;
          pcStack_168 = (code *)0x0;
          plStack_170 = (longlong *)0x0;
          plStack_178 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          plVar7 = (longlong *)0x0;
          iVar6 = 0xf5;
          pcStack_120 = _PyRuntime_exref;
        }
      }
    }
LAB_23e7f61b4:
    pcVar14 = apcStack_98[0];
    pcVar11 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar11 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar18 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar18;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar11 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    lVar12 = *(longlong *)(pcStack_120 + 0x1f8);
    *(int *)(pcVar11 + 0x24) = iVar6;
    *(undefined4 *)(pcVar11 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(*(longlong *)(lVar12 + 0x10) + 0x2e8);
    lVar20 = *(longlong *)(pcVar11 + -8);
    puVar19 = *(undefined8 **)(lVar12 + 8);
    *puVar19 = pcVar11 + -0x10;
    *(longlong *)(pcVar11 + -0x10) = lVar12;
    *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar19;
    *(code **)(lVar12 + 8) = pcVar11 + -0x10;
    *(code **)(pcVar11 + 0x10) = pcVar14;
    *(longlong *)pcVar14 = *(longlong *)pcVar14 + 1;
    pcVar14 = apcStack_98[0];
    plVar13 = plVar8;
  }
  else {
    iVar6 = *(int *)(lVar12 + 0xc);
    if (*(int *)(lVar12 + 0xc) == 0) {
      *(int *)(lVar12 + 0xc) = DAT_23ec15618;
      iVar6 = DAT_23ec15618;
      DAT_23ec15618 = DAT_23ec15618 + 1;
    }
    if (_DAT_23ec155e0 != iVar6) {
      _DAT_23ec155e0 = iVar6;
      _DAT_23eedea60 = FUN_23e8cbd60(lVar12,_DAT_23eeddf50,*(undefined8 *)(_DAT_23eeddf50 + 0x18));
    }
    if (-1 < _DAT_23eedea60) {
      lVar20 = lVar12 + 0x20 + (1L << (*(byte *)(lVar12 + 9) & 0x3f));
      if (*(longlong *)(lVar20 + 8 + _DAT_23eedea60 * 0x10) != 0) goto LAB_23e7f57bd;
      _DAT_23eedea60 = FUN_23e8cbd60(lVar12,_DAT_23eeddf50,*(undefined8 *)(_DAT_23eeddf50 + 0x18));
      if (-1 < _DAT_23eedea60) {
        lVar12 = *(longlong *)(lVar20 + 8 + _DAT_23eedea60 * 0x10);
        goto LAB_23e7f6c58;
      }
    }
LAB_23e7f5ca9:
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,_DAT_23eeddf50);
    if ((plVar7 != (longlong *)0x0) && (*plVar7 != 0)) goto LAB_23e7f57bd;
    FUN_23e915740(param_1,auStack_a8,_DAT_23eeddf50);
    if (apcStack_98[0] != (code *)0x0) {
      if (*(longlong **)(apcStack_98[0] + 0x18) != plVar2) {
        plVar8 = (longlong *)0x0;
        plStack_138 = (longlong *)0x0;
        plVar7 = (longlong *)0x0;
        plStack_140 = (longlong *)0x0;
        iVar6 = 0xf2;
        pcStack_148 = (code *)0x0;
        plStack_150 = (longlong *)0x0;
        pcStack_158 = (code *)0x0;
        plStack_128 = (longlong *)0x0;
        pcStack_130 = (code *)0x0;
        plStack_170 = (longlong *)0x0;
        plStack_178 = (longlong *)0x0;
        plStack_160 = (longlong *)0x0;
        pcStack_168 = (code *)0x0;
        plStack_198 = (longlong *)0x0;
        plStack_188 = (longlong *)0x0;
        plStack_190 = (longlong *)0x0;
        pcStack_120 = _PyRuntime_exref;
        goto LAB_23e7f61b4;
      }
LAB_23e7f68e8:
      plStack_138 = (longlong *)0x0;
      plVar13 = (longlong *)0x0;
      plVar7 = (longlong *)0x0;
      plStack_140 = (longlong *)0x0;
      pcStack_148 = (code *)0x0;
      plStack_150 = (longlong *)0x0;
      pcStack_158 = (code *)0x0;
      plStack_128 = (longlong *)0x0;
      pcStack_130 = (code *)0x0;
      plStack_170 = (longlong *)0x0;
      plStack_178 = (longlong *)0x0;
      plStack_160 = (longlong *)0x0;
      pcStack_168 = (code *)0x0;
      plStack_198 = (longlong *)0x0;
      plStack_188 = (longlong *)0x0;
      plStack_190 = (longlong *)0x0;
      pcVar11 = apcStack_98[0];
      goto LAB_23e7f6266;
    }
LAB_23e7f7b78:
    plVar8 = (longlong *)0x0;
    plStack_138 = (longlong *)0x0;
    plVar7 = (longlong *)0x0;
    plStack_140 = (longlong *)0x0;
    iVar6 = 0xf2;
    pcStack_148 = (code *)0x0;
    plStack_150 = (longlong *)0x0;
    pcStack_158 = (code *)0x0;
    plStack_128 = (longlong *)0x0;
    pcStack_130 = (code *)0x0;
    plStack_170 = (longlong *)0x0;
    plStack_178 = (longlong *)0x0;
    plStack_160 = (longlong *)0x0;
    pcStack_168 = (code *)0x0;
    plStack_198 = (longlong *)0x0;
    plStack_188 = (longlong *)0x0;
    plStack_190 = (longlong *)0x0;
    pcStack_120 = _PyRuntime_exref;
LAB_23e7f7491:
    pcVar11 = DAT_23ed6a4f8;
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar11 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      pcVar14 = apcStack_98[0];
    }
    else {
      pcVar14 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      pcVar14 = (code *)0x0;
    }
    *(longlong **)(pcVar11 + 0x18) = plVar2;
    *(longlong *)(pcVar11 + 0x10) = 0;
    *plVar2 = *plVar2 + 1;
    lVar12 = *(longlong *)(pcStack_120 + 0x1f8);
    *(undefined4 *)(pcVar11 + 0x20) = 0xffffffff;
    lVar12 = *(longlong *)(lVar12 + 0x10);
    *(int *)(pcVar11 + 0x24) = iVar6;
    lVar12 = *(longlong *)(lVar12 + 0x2e8);
    lVar20 = *(longlong *)(pcVar11 + -8);
    puVar19 = *(undefined8 **)(lVar12 + 8);
    *puVar19 = pcVar11 + -0x10;
    *(longlong *)(pcVar11 + -0x10) = lVar12;
    *(ulonglong *)(pcVar11 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar19;
    *(code **)(lVar12 + 8) = pcVar11 + -0x10;
    plVar13 = plVar8;
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))();
  }
LAB_23e7f6266:
  apcStack_98[0] = pcVar11;
  FUN_23e8bba40(plVar2,"ooooooooooooooooo",param_3,plStack_190,plStack_188,plStack_198,pcStack_168,
                plStack_160,plStack_178,plStack_170,plVar7,pcStack_130,plStack_128,pcStack_158,
                plStack_150,pcStack_148,plStack_140,plStack_138,plVar13);
  if (_DAT_23eedea80 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    _DAT_23eedea80 = (longlong *)0x0;
  }
  lVar12 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar12 + 0x28);
  plVar8 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar12 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  pcVar14 = apcStack_98[0];
  pcVar11 = pcStack_a0;
  auVar9 = auStack_a8;
  plVar2[0xf] = 0;
  _auStack_a8 = (undefined1  [16])0x0;
  apcStack_98[0] = (code *)0x0;
  if ((plStack_190 != (longlong *)0x0) &&
     (lVar12 = *plStack_190, *plStack_190 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_190[1] + 0x30))(plStack_190);
  }
  if ((plStack_188 != (longlong *)0x0) &&
     (lVar12 = *plStack_188, *plStack_188 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_188[1] + 0x30))(plStack_188);
  }
  if ((plStack_198 != (longlong *)0x0) &&
     (lVar12 = *plStack_198, *plStack_198 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_198[1] + 0x30))(plStack_198);
  }
  if ((pcStack_168 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_168, *(longlong *)pcStack_168 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_168 + 8) + 0x30))(pcStack_168);
  }
  if ((plStack_160 != (longlong *)0x0) &&
     (lVar12 = *plStack_160, *plStack_160 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_160[1] + 0x30))(plStack_160);
  }
  if ((plStack_178 != (longlong *)0x0) &&
     (lVar12 = *plStack_178, *plStack_178 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_178[1] + 0x30))(plStack_178);
  }
  if ((plStack_170 != (longlong *)0x0) &&
     (lVar12 = *plStack_170, *plStack_170 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_170[1] + 0x30))(plStack_170);
  }
  if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if ((pcStack_130 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_130, *(longlong *)pcStack_130 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_130 + 8) + 0x30))(pcStack_130);
  }
  if ((plStack_128 != (longlong *)0x0) &&
     (lVar12 = *plStack_128, *plStack_128 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_128[1] + 0x30))(plStack_128);
  }
  if ((pcStack_158 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_158, *(longlong *)pcStack_158 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_158 + 8) + 0x30))(pcStack_158);
  }
  if ((plStack_150 != (longlong *)0x0) &&
     (lVar12 = *plStack_150, *plStack_150 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_150[1] + 0x30))(plStack_150);
  }
  if ((pcStack_148 != (code *)0x0) &&
     (lVar12 = *(longlong *)pcStack_148, *(longlong *)pcStack_148 = lVar12 + -1, lVar12 + -1 == 0))
  {
    (**(code **)(*(longlong *)(pcStack_148 + 8) + 0x30))(pcStack_148);
  }
  if ((plStack_140 != (longlong *)0x0) &&
     (lVar12 = *plStack_140, *plStack_140 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_140[1] + 0x30))(plStack_140);
  }
  if ((plStack_138 != (longlong *)0x0) &&
     (lVar12 = *plStack_138, *plStack_138 = lVar12 + -1, lVar12 + -1 == 0)) {
    (**(code **)(plStack_138[1] + 0x30))(plStack_138);
  }
  if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  lVar12 = *param_3;
  *param_3 = lVar12 + -1;
  apcStack_98[0] = pcVar14;
  auStack_a8 = auVar9;
  pcStack_a0 = pcVar11;
  if (lVar12 + -1 == 0) {
    (**(code **)(param_3[1] + 0x30))(param_3);
  }
  FUN_23a33aa70(param_1,auStack_a8,pcStack_a0,apcStack_98[0]);
  return (code *)0x0;
LAB_23e7f71ad:
  if (*(int *)(lVar12 + 0x68) == 0) {
    plVar16 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar16 = *(longlong **)(param_1 + 0x90);
  }
  if (plVar16 != (longlong *)0x0) {
    plVar17 = *(longlong **)(param_1 + 0x60);
    *(undefined8 *)(param_1 + 0x90) = 0;
    plVar10 = *(longlong **)(param_1 + 0x68);
    *(longlong **)(param_1 + 0x60) = plVar16;
    plVar3 = *(longlong **)(param_1 + 0x70);
    *plVar16 = *plVar16 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      (**(code **)(plVar17[1] + 0x30))();
    }
    if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
      (**(code **)(plVar10[1] + 0x30))();
    }
    if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
      (**(code **)(plVar3[1] + 0x30))();
    }
    auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
LAB_23e7f729f:
    pcVar18 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar14 = *(code **)(param_1 + 0x68);
    iVar6 = 0x100;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e7f72f0;
  }
  goto LAB_23e7f6f20;
LAB_23e7fa1dc:
  do {
    uVar22 = (undefined4)((ulonglong)in_stack_fffffffffffffde8 >> 0x20);
    plVar15 = (longlong *)FUN_23a388450(plVar13);
    if (plVar15 == (longlong *)0x0) {
      cVar5 = FUN_23a3591a0(param_1,*(undefined8 *)PyExc_StopIteration_exref);
      if (cVar5 == '\0') {
        pcVar11 = *(code **)(param_1 + 0x70);
        auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcVar14 = *(code **)(param_1 + 0x68);
        *(undefined8 *)(param_1 + 0x70) = 0;
        iVar6 = 0x122;
        apcStack_98[0] = (code *)0x0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        auStack_a8 = (undefined1  [8])0x0;
        pcStack_a0 = (code *)0x0;
        if (plStack_f8 == (longlong *)0x0) goto LAB_23e7fae82;
        goto LAB_23e7fae74;
      }
      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
      if ((plStack_f8 != (longlong *)0x0) && (*plStack_f8 = *plStack_f8 + -1, *plStack_f8 == 0)) {
        FUN_23a334bc0(plStack_f8);
      }
      lVar12 = *plVar13;
      *plVar13 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0(plVar13);
      }
      pcVar11 = _Py_NoneStruct_exref;
      *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
      lVar12 = *plStack_190;
      *plStack_190 = lVar12 + -1;
      if (lVar12 + -1 != 0) goto LAB_23e7f59ee;
      goto LAB_23e7f59d4;
    }
    if ((plStack_f8 != (longlong *)0x0) && (*plStack_f8 = *plStack_f8 + -1, *plStack_f8 == 0)) {
      FUN_23a334bc0(plStack_f8);
    }
    plVar16 = (longlong *)FUN_23a388310();
    plStack_f8 = plVar15;
    if (plVar16 == (longlong *)0x0) {
      pcVar11 = *(code **)(param_1 + 0x70);
      auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
      pcVar14 = *(code **)(param_1 + 0x68);
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7fae20:
      iVar6 = 0x122;
      pcStack_118 = pcStack_168;
      plStack_110 = plVar8;
      goto LAB_23e7fae3e;
    }
    uVar21 = CONCAT44(uVar22,4);
    plVar15 = (longlong *)FUN_23a3c1d30(param_1,auStack_a8,plVar16,0,uVar21);
    if (plVar15 == (longlong *)0x0) {
      plStack_110 = (longlong *)0x0;
      lVar12 = *plVar16;
      plVar17 = (longlong *)0x0;
      pcStack_118 = (code *)0x0;
LAB_23e7fb1e0:
      pcVar11 = apcStack_98[0];
      pcVar14 = pcStack_a0;
      auVar9 = auStack_a8;
      _auStack_a8 = (undefined1  [16])0x0;
      apcStack_98[0] = (code *)0x0;
      *plVar16 = lVar12 + -1;
      if (lVar12 + -1 == 0) {
        FUN_23a334bc0();
      }
      apcStack_98[0] = (code *)0x0;
      _auStack_a8 = (undefined1  [16])0x0;
      if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
        FUN_23a334bc0();
      }
      if ((pcStack_118 != (code *)0x0) &&
         (lVar12 = *(longlong *)pcStack_118, *(longlong *)pcStack_118 = lVar12 + -1,
         lVar12 + -1 == 0)) {
        FUN_23a334bc0();
      }
      if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
        FUN_23a334bc0();
      }
      if ((plStack_110 != (longlong *)0x0) &&
         (lVar12 = *plStack_110, *plStack_110 = lVar12 + -1, lVar12 + -1 == 0)) {
        FUN_23a334bc0();
      }
      goto LAB_23e7fae20;
    }
    uVar21 = CONCAT44((int)((ulonglong)uVar21 >> 0x20),4);
    pcStack_118 = (code *)FUN_23a3c1d30(param_1,auStack_a8,plVar16,1,uVar21);
    if (pcStack_118 == (code *)0x0) {
      plVar17 = (longlong *)0x0;
      plStack_110 = (longlong *)0x0;
      lVar12 = *plVar16;
      goto LAB_23e7fb1e0;
    }
    uVar21 = CONCAT44((int)((ulonglong)uVar21 >> 0x20),4);
    plVar17 = (longlong *)FUN_23a3c1d30(param_1,auStack_a8,plVar16,2,uVar21);
    if (plVar17 == (longlong *)0x0) {
      lVar12 = *plVar16;
      plStack_110 = (longlong *)0x0;
      goto LAB_23e7fb1e0;
    }
    in_stack_fffffffffffffde8 = CONCAT44((int)((ulonglong)uVar21 >> 0x20),4);
    plStack_110 = (longlong *)FUN_23a3c1d30(param_1,auStack_a8,plVar16,3,in_stack_fffffffffffffde8);
    if (plStack_110 == (longlong *)0x0) {
      lVar12 = *plVar16;
      goto LAB_23e7fb1e0;
    }
    cVar5 = FUN_23a3884a0(param_1,auStack_a8,plVar16);
    lVar12 = *plVar16;
    if (cVar5 == '\0') goto LAB_23e7fb1e0;
    *plVar16 = lVar12 + -1;
    if (lVar12 + -1 == 0) {
      FUN_23a334bc0(plVar16);
    }
    *plVar15 = *plVar15 + 1;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      FUN_23a334bc0(plVar8);
    }
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    *(longlong *)pcStack_118 = *(longlong *)pcStack_118 + 1;
    if ((pcStack_168 != (code *)0x0) &&
       (lVar12 = *(longlong *)pcStack_168, *(longlong *)pcStack_168 = lVar12 + -1, lVar12 + -1 == 0)
       ) {
      FUN_23a334bc0(pcStack_168);
    }
    *(longlong *)pcStack_118 = *(longlong *)pcStack_118 + -1;
    if (*(longlong *)pcStack_118 == 0) {
      FUN_23a334bc0(pcStack_118);
    }
    *plVar17 = *plVar17 + 1;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      FUN_23a334bc0(plVar15);
    }
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      FUN_23a334bc0(plVar17);
    }
    *plStack_110 = *plStack_110 + 1;
    *plVar17 = *plVar17 + -1;
    if (*plVar17 == 0) {
      FUN_23a334bc0(plVar17);
    }
    *plStack_110 = *plStack_110 + -1;
    if (*plStack_110 == 0) {
      FUN_23a334bc0(plStack_110);
    }
    lVar12 = FUN_23e8dd910();
    uVar21 = _DAT_23eeddf78;
    if (lVar12 == 0) {
      FUN_23e915740(param_1,auStack_a8,_DAT_23eeddc10);
LAB_23e7fa406:
      pcVar11 = apcStack_98[0];
      pcStack_e0 = pcStack_a0;
      pcStack_e8 = (code *)auStack_a8;
      auStack_a8 = (undefined1  [8])0x0;
      pcStack_a0 = (code *)0x0;
      plVar8 = *(longlong **)(param_1 + 0x138);
      apcStack_98[0] = (code *)0x0;
      pcStack_d8 = pcVar11;
      if (plVar8 != (longlong *)0x0) {
        *plVar8 = *plVar8 + 1;
      }
      if (pcVar11 == (code *)0x0) {
        lVar12 = FUN_23e8d6280(plVar2,0x124);
      }
      else {
        lVar12 = FUN_23e8d6280(plVar2,0x124);
        *(code **)(lVar12 + 0x10) = pcVar11;
        *(longlong *)pcVar11 = *(longlong *)pcVar11 + 1;
      }
      if ((pcStack_d8 != (code *)0x0) &&
         (*(longlong *)pcStack_d8 = *(longlong *)pcStack_d8 + -1, *(longlong *)pcStack_d8 == 0)) {
        FUN_23a334bc0();
      }
      pcStack_d8 = (code *)lVar12;
      FUN_23a35ef40(param_1,&pcStack_e8);
      iVar6 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                            *(undefined8 *)PyExc_Exception_exref);
      if (iVar6 == 0) {
        cVar5 = FUN_23e8ba320(*(undefined8 *)(param_1 + 0x138),auStack_a8);
        pcVar11 = apcStack_98[0];
        pcVar14 = pcStack_a0;
        auVar9 = auStack_a8;
        iVar6 = 0;
        if (cVar5 == '\0') {
          iVar6 = 0x123;
        }
        if ((apcStack_98[0] != (code *)0x0) && (*(longlong **)(apcStack_98[0] + 0x18) == plVar2)) {
          *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(apcStack_98[0] + 0x24);
        }
        apcStack_98[0] = (code *)0x0;
        _auStack_a8 = (undefined1  [16])0x0;
        FUN_23ebf6ae0();
        goto LAB_23e7fae3e;
      }
      FUN_23ebf6ae0(param_1);
    }
    else {
      *(undefined4 *)(plVar2 + 5) = 0x124;
      plVar8 = (longlong *)FUN_23e915840(param_1,lVar12,uVar21);
      if (plVar8 == (longlong *)0x0) {
        apcStack_98[0] = *(code **)(param_1 + 0x70);
        auStack_a8 = *(undefined1 (*) [8])(param_1 + 0x60);
        pcStack_a0 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        goto LAB_23e7fa406;
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        FUN_23a334bc0();
      }
    }
    cVar5 = FUN_23a3a5fe0();
    plVar8 = plStack_110;
    pcStack_168 = pcStack_118;
  } while (cVar5 != '\0');
  auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
  pcVar14 = *(code **)(param_1 + 0x68);
  pcVar11 = *(code **)(param_1 + 0x70);
  iVar6 = 0x122;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e7fae3e:
  pcStack_168 = pcStack_118;
  plVar8 = plStack_110;
LAB_23e7fae74:
  pcStack_a0 = (code *)0x0;
  auStack_a8 = (undefined1  [8])0x0;
  apcStack_98[0] = (code *)0x0;
  *plStack_f8 = *plStack_f8 + -1;
  if (*plStack_f8 == 0) {
    FUN_23a334bc0();
  }
LAB_23e7fae82:
  lVar12 = *plVar13;
  *plVar13 = lVar12 + -1;
  if (lVar12 + -1 == 0) {
    FUN_23a334bc0();
  }
LAB_23e7fa79a:
  apcStack_98[0] = pcVar11;
  auStack_a8 = auVar9;
  pcStack_a0 = pcVar14;
  if (pcVar11 == (code *)0x0) {
    if (iVar6 == 0) {
      iVar6 = (int)plVar2[5];
    }
    goto LAB_23e7f7491;
  }
  plVar13 = plVar8;
  if (*(longlong **)(pcVar11 + 0x18) == plVar2) goto LAB_23e7f6266;
  if (iVar6 == 0) {
    iVar6 = (int)plVar2[5];
  }
  goto LAB_23e7f61b4;
LAB_23e7f8742:
  if (*(int *)(lVar12 + 0x68) == 0) {
    plVar15 = *(longlong **)(param_1 + 0x90);
  }
  else {
    PyEval_SaveThread();
    PyEval_AcquireThread(param_1);
    plVar15 = *(longlong **)(param_1 + 0x90);
  }
  pcStack_158 = pcStack_118;
  if (plVar15 != (longlong *)0x0) {
    plVar8 = *(longlong **)(param_1 + 0x60);
    *(longlong **)(param_1 + 0x60) = plVar15;
    plVar16 = *(longlong **)(param_1 + 0x68);
    plVar17 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x90) = 0;
    *plVar15 = *plVar15 + 1;
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
      (**(code **)(plVar8[1] + 0x30))();
    }
    if ((plVar16 != (longlong *)0x0) && (*plVar16 = *plVar16 + -1, *plVar16 == 0)) {
      (**(code **)(plVar16[1] + 0x30))();
    }
    if ((plVar17 != (longlong *)0x0) && (*plVar17 = *plVar17 + -1, *plVar17 == 0)) {
      (**(code **)(plVar17[1] + 0x30))();
    }
LAB_23e7f8aae:
    pcVar11 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    auVar9 = *(undefined1 (*) [8])(param_1 + 0x60);
    pcVar14 = *(code **)(param_1 + 0x68);
    iVar6 = 0x113;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e7f8ade;
  }
  goto LAB_23e7f8523;
}
